package in.logikx.important;

/**
 * 
 * @author aseem
 *
 */
public class JsonGenerator {
	
	public JsonNode createJson(String[] rules){
		JsonNode node = new JsonNode();
		for(String rule : rules){
			String[] tokens = rule.split(">|\\=");
			int size = tokens.length;
			JsonNode currentNode = node;
			for(String token : rules){
				if(size != 1){
					size--;
					if(!currentNode.getAllKeys().contains(token)){
						if(size == 2){
							currentNode.addValue(token, tokens[tokens.length-1]);
						}
						currentNode.addJsonPair(token);
						
					}else{
						if(size == 2){
							currentNode = currentNode.getJsonNodeFromKey(token);
						}else{
							//TODO : throw error
						}
					}
				}
			}
		}
		
		return null;		
	}
}
