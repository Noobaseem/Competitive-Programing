package in.logikx.important;

/**
 * 
 * @author aseem
 *
 */
public class JsonPair {
	
	String jsonKey;
	
	JsonValue jsonValue;
	
	
	public String getJsonKey() {
		return jsonKey;
	}

	public void setJsonKey(String jsonKey) {
		this.jsonKey = jsonKey;
	}

	public JsonValue getJsonValue() {
		return jsonValue;
	}
	
	public void setJsonValue(JsonValue jsonValue) {
		this.jsonValue = jsonValue;
	}
	
	public String toString(){
		String returnValue = "'"+jsonKey+"' : "+jsonValue.toString();
		return returnValue;
	}
}
