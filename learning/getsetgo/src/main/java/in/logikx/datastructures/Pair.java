package in.logikx.datastructures;

/**
 * There does not exist any datastructure for pair in the java util package.
 * I loved the c++ Pair structure and thought of implementing the same in java.
 * 
 * 
 * @author aseem
 *
 * @param <L>
 * @param <R>
 */
public class Pair<L,R> {
	
	private L left;
	private R right;
	
	public Pair(L left, R right){
		this.left = left;
		this.right = right;
	}
	
	public L getLeft(){
		return this.left;
	}
	
	public R getRight(){
		return this.right;
	}
	
	public int hashCode(){
		return this.left.hashCode()^this.right.hashCode();
	}

	public boolean equals(Object o){
		if (!(o instanceof Pair)) return false;
		Pair<?, ?> pair = (Pair<?, ?>) o;
		return this.left.equals(pair.getLeft()) && this.right.equals(pair.getRight());
	}
}
