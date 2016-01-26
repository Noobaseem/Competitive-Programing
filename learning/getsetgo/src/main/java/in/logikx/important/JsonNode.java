package in.logikx.important;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

/**
 * 
 * @author aseem
 *
 */
public class JsonNode {
	
	List<JsonPair> elements = null;
	
	public List<JsonPair> getElements(){
		return this.elements;
	}
	
	public void addJsonPair(String key){
		JsonPair pair = new JsonPair();
		pair.setJsonKey(key);
		pair.setJsonValue(null);
		elements.add(pair);
	}
	
	public JsonNode getJsonNodeFromKey(String key){
		for(JsonPair pair : elements){
			if(pair.getJsonKey() == key){
				return pair.getJsonValue().getComplexValue();
			}
		}
		return null;
	}
	
	
	public Set<String> getAllKeys(){
		Set<String> keys = null;
		if(elements == null){
			return null;
		}else{
			for(JsonPair pair : elements){
				keys.add(pair.getJsonKey());
			}
		}
		return keys;
	}

	public void addValue(String key, String token) {
		if(elements == null){
			elements = new ArrayList<JsonPair>();
			JsonPair pair = new JsonPair();
			pair.setJsonKey(key);
			pair.getJsonValue().setIntAndArrayValue(token);
			elements.add(pair);
		}
	}
}
