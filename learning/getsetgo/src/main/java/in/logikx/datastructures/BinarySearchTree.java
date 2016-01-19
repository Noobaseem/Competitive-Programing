package in.logikx.datastructures;

/**
 * 
 * @author aseem
 *
 * @param <E>
 */
public interface BinarySearchTree<E> {
	
	public void insert(E element);
	
	public E find(E item, BinaryTreeNode<E> parent, BinaryTreeNode<E> location);
	
	public void delete(E element);
	
	public void getLCA(E element1, E element2);
	
	public int getHeight(BinaryTreeNode<E> root);
	
	public int getDiameter(BinaryTreeNode<E> root);
	
	public int getMaxElement(BinaryTreeNode<E> root);
	
	public int getMinElement(BinaryTreeNode<E> root);
}
