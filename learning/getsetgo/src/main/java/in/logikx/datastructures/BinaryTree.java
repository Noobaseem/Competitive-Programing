package in.logikx.datastructures;

/**
 * 
 * @author aseem
 *
 * @param <E>
 */
public interface BinaryTree<E> {
	
	public int getHeight(BinaryTreeNode<E> root);
	
	public int getDiameter(BinaryTreeNode<E> root);
	
	public int getMaxElement(BinaryTreeNode<E> root);
	
	public int getMinElement(BinaryTreeNode<E> root);
}
