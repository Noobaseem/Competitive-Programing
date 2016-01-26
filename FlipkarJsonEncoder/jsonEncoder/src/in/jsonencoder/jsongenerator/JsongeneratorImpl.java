package in.jsonencoder.jsongenerator;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * This is a concrete class to generate the json structure from the parsed tokens
 * 
 * @author aseem
 *
 */
public class JsongeneratorImpl implements Jsongenerator {

	public static HashMap<String, Jsonvalues> json = null;
	
	/*
	 * This is a recursive approach to fill the jsonValues
	 */
	public String generate(String[] tokens) {
		int length = tokens.length;
		HashMap<String, Jsonvalues> temp = null;
		
		if(json == null){
			json = new HashMap<String, Jsonvalues>();
		}
		temp = json;
		
		for(int iterator = 0; iterator < length-1; iterator++){			
			String token = tokens[iterator];
			
			if(!temp.isEmpty() && temp.containsKey(token)){
				if(iterator < length - 2){
					Jsonvalues value = temp.get(token);
					temp = value.getComplexValue();
				}else{
					Jsonvalues value = temp.get(token);
					value.getSimpleValue().add(tokens[iterator+1]);
				}
			}else{
				if(iterator < length - 2){
					Jsonvalues value = new Jsonvalues();
					value.setSimpleValue(null);
					value.setComplexValue(new HashMap<String, Jsonvalues>());
					value.setLevel(iterator+2);
					temp.put(token, value);
					temp = temp.get(token).getComplexValue();
				}else{
					Jsonvalues value = new Jsonvalues();
					value.setComplexValue(null);
					value.setSimpleValue(new ArrayList<String>());
					value.setLevel(iterator+2);
					value.getSimpleValue().add(tokens[iterator+1]);
					temp.put(token, value);
				}
			}
		}
		return json.toString();
	}
	
	public static HashMap<String, Jsonvalues> getJson() {
		return json;
	}

	public static void setJson(HashMap<String, Jsonvalues> json) {
		JsongeneratorImpl.json = json;
	}

	public String toString(){
		StringBuilder string = new StringBuilder();
		string.append("{");
		String prefix = "";
		for(String key : json.keySet()){
			Jsonvalues value = json.get(key);
			String valueString = json.get(key).getValue(value);
			string.append(prefix+"\n")
			.append("\t")
			.append(key)
			.append(valueString);
			prefix=",";
		}
		string.append("\n}");
		return string.toString();
		
	}
	
}
