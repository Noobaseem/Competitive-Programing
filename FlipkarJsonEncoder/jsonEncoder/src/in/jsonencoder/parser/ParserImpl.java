package in.jsonencoder.parser;

import in.jsonencoder.jsongenerator.JsongeneratorImpl;

/**
 * 
 * @author aseem
 *
 */
public class ParserImpl implements Parser {

	public String generateTokens(String[] input) {
		String[] tokens = null;
		JsongeneratorImpl generator = new JsongeneratorImpl();
		//Parse each line
		for(String line : input){
			tokens = line.split("=|\\.");
			generator.generate(tokens);
		}		
		return generator.toString();
	}

}
