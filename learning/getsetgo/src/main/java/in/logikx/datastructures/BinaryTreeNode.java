package in.logikx.datastructures;

/**
 * 
 * @author aseem
 *
 * @param <E>
 */
public class BinaryTreeNode<E> {
	
	E value = null;
	BinaryTreeNode<E> left = null;
	BinaryTreeNode<E> right = null;
	
	public E getValue() {
		return value;
	}
	
	public void setValue(E value) {
		this.value = value;
	}
	
	public BinaryTreeNode<E> getLeft() {
		return left;
	}

	public void setLeft(BinaryTreeNode<E> left) {
		this.left = left;
	}

	public BinaryTreeNode<E> getRight() {
		return right;
	}

	public void setRight(BinaryTreeNode<E> right) {
		this.right = right;
	}
}
