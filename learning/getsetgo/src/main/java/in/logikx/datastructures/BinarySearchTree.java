package in.logikx.datastructures;

/**
 * 
 * @author aseem
 *
 * @param <E>
 */
public interface BinarySearchTree<E> {
	
	public void insert(E element);

	public void find(E item, BinaryTreeNode<E> location, BinaryTreeNode<E> parentLocation);
	
	public void delete(E element);
	
	public void deleteCaseA(BinaryTreeNode<E> location, BinaryTreeNode<E> parentLocation);
	
	public void deleteCaseB(BinaryTreeNode<E> location, BinaryTreeNode<E> parentLocation);
	
	public void deleteCaseC(BinaryTreeNode<E> location, BinaryTreeNode<E> parentLocation);
	
	public void inorderTraversal(BinaryTreeNode<E> currentNode);
	
	public void preOrderTraversal(BinaryTreeNode<E> currentNode);
	
	public void postOrderTraversal(BinaryTreeNode<E> currentNode);
	
	public void processCurrentNode(BinaryTreeNode<E> currentNode);
	
	public void getLCA(E element1, E element2);
	
	public int getHeight();
	
	public int getDiameter();
	
	public int getMaxElement();
	
	public int getMinElement();
}
