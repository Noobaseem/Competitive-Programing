package in.jsongenerator.testrunner;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

import in.jsonencoder.parser.ParserImpl;

/**
 * 
 * @author aseem
 *
 */
public class Jsonapp {
	
	public void go() throws NumberFormatException, IOException{
		int nLines = 0;
		Scanner stdin = new Scanner(new BufferedInputStream(System.in));
		int iterator = 0;
		nLines = stdin.nextInt();
		String[] lines = new String[nLines];
		while(iterator < nLines){
			lines[iterator++] = stdin.next();
		}
		
		ParserImpl parser = new ParserImpl();
		String jsonResponse = parser.generateTokens(lines);
		System.out.println(jsonResponse);
		
	}
	
	public static void main(String[] args){
		Jsonapp app = new Jsonapp();
		try {
			app.go();
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			System.out.println("There was a number format exception");
		}
	}
}
