package in.logikx.datastructures;

/**
 * 
 * 
 * @author aseem
 *
 */
public class AdjListElement {
	
	public int target;
	public int weight;
	
	public AdjListElement(int target, int weight){
		this.target = target;
		this.weight = weight;
	}
	
	/*
	 * (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	public String toString(){
		return "("+target+" ; "+weight+")";
	}
}
