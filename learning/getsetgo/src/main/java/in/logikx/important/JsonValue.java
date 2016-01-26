package in.logikx.important;

import java.util.List;

/**
 * 
 * @author aseem
 *
 */
public class JsonValue {
	
	List<String> intAndArrayValue = null;
	
	JsonNode complexValue = null;
	
	public JsonNode getComplexValue() {
		return complexValue;
	}

	public List<String> getIntAndArrayValue() {
		return intAndArrayValue;
	}

	public void setIntAndArrayValue(String value) {
		this.getIntAndArrayValue().add(value);
	}

	public void setComplexValue(JsonNode complexValue) {
		this.complexValue = complexValue;
	}

	public String toString(){
		if(intAndArrayValue != null){
			if(intAndArrayValue.size() == 1){
				return intAndArrayValue.toString()+",";
			}else{
				String returnValue = "[";
				for(String e : intAndArrayValue){
					returnValue = returnValue+""+e.toString()+",";
				}
				returnValue = returnValue+"]";
				return returnValue;
			}
		}else{
			return "{"+complexValue.toString()+"}";
		}
	}
}
