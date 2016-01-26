package in.jsonencoder.jsongenerator;

import java.util.HashMap;
import java.util.List;

/**
 * <h3>This is the concrete class that defines the type of Values the json object can support<h3>
 * <p>It can support following values : </p>
 * <p>1. Simple Integers</p>
 * <p>2. Simple Strings</p>
 * <p>3. Array of Strings/Integers</p>
 * <p>4. Json object itself</p>
 * 
 * But if we look carefully there is a catch because all the values can either be classified as List<String> or json objects,
 * thus I have made a classification for these two types only. Other types can be inferred from these types only
 * 
 * @author aseem
 *
 */
public class Jsonvalues {
	
	List<String> simpleValue = null;
	
	HashMap<String, Jsonvalues> complexValue = null;
	
	Integer level = 0;
	
	public Integer getLevel() {
		return level;
	}

	public void setLevel(Integer level) {
		this.level = level;
	}

	public List<String> getSimpleValue() {
		return simpleValue;
	}
	
	public void setSimpleValue(List<String> simpleValue) {
		this.simpleValue = simpleValue;
	}
	
	public HashMap<String, Jsonvalues> getComplexValue() {
		return complexValue;
	}
	
	public void setComplexValue(HashMap<String, Jsonvalues> complexValue) {
		this.complexValue = complexValue;
	}
	
	public String getValue(Jsonvalues value){
		return value.toString();
	}
	
	public String toString(){
		String returnValue = null;
		String prefix = "";
		String tabsToGive = "";
		String tabsToGiveClosing = "";
		StringBuilder str = new StringBuilder();
		boolean isIndented = false;
		if(this.getSimpleValue() != null){
			if(this.getSimpleValue().size() > 1){
				str.append(" : [");
				for(String value : this.getSimpleValue()){
					str.append(prefix);
					prefix=",";
					str.append(value);
				}
				str.append("]");
				returnValue = str.toString();
			}else{
				return " : "+this.getSimpleValue().get(0);
			}
		}else{
			if(!this.getComplexValue().isEmpty()){
				str.append(" : {\n");
				for(int i = 0; i < this.getLevel(); i++){
					tabsToGive += "\t";
					if(i>0){
						tabsToGiveClosing += "\t";
					}
					isIndented = true;
				}
				prefix = "";
				for(String key : this.getComplexValue().keySet()){
					Jsonvalues value = this.getComplexValue().get(key);
					String valueString = this.getComplexValue().get(key).getValue(value);
					str.append(prefix);
					
					if(isIndented){
						str.append("\n");
					}
					
					str.append(tabsToGive)
					.append(key)
					.append(valueString);
					prefix=",";
				}
				str.append("\n"+tabsToGiveClosing+"}");
				returnValue = str.toString();
			}
		}
		
		return returnValue;
	}
}
