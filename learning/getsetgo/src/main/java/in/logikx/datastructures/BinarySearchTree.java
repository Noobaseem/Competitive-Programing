package in.logikx.datastructures;

public interface BinarySearchTree<E> {
	
	public void insert(E element);
	
	public void delete(E element);
	
	public void getLCA(E element1, E element2);
	
	public int getHeight(BinaryTreeNode<E> root);
	
	public int getDiameter(BinaryTreeNode<E> root);
	
	public int getMaxElement(BinaryTreeNode<E> root);
	
	public int getMinElement(BinaryTreeNode<E> root);
}
