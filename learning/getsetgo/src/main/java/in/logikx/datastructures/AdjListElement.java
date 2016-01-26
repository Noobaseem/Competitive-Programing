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
	
	public int getTarget() {
		return target;
	}

	public void setTarget(int target) {
		this.target = target;
	}

	public int getWeight() {
		return weight;
	}

	public void setWeight(int weight) {
		this.weight = weight;
	}
	
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
