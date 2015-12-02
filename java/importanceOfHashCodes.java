/* package whatever; // don't place package name! */
/*
	HasCodes of the object are really important things, they help to uniquely identify each object
	This is the reason while objectifying something and recasting to original form works because each object has unique hashCode
*/


import java.util.*;
import java.lang.*;
import java.io.*;

class dog{
	String bark;
	void dogBark(){
		System.out.println(bark);
	}
	void setBark(String bark){
		this.bark = bark;
	}
}

/* Name of the class has to be "Main" only if the class is public. */
class ImportanceOfHashCodes {
	
	Object getObject(Object o){
		return o;
	}
	
	public static void main (String[] args) throws java.lang.Exception {
		dog tommy = new dog();
		tommy.setBark("bow bow");
		tommy.dogBark();
		dog prince = new dog();
		prince.setBark("bowwwwwww");
		prince.dogBark();
		ImportanceOfHashCodes myObj = new ImportanceOfHashCodes();
		/*String myClassName = myObj.getObject(tommy).getClass().toString();
		System.out.println(myClassName);*/
		dog sheru = (dog) myObj.getObject(tommy);
		tommy.setBark("growl......");
		sheru.dogBark();
		System.out.println(myObj.getObject(tommy).hashCode());
		System.out.println(myObj.getObject(prince).hashCode());
	}
}