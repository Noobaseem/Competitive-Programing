package in.logikx.datastructures;

import java.util.Comparator;
/**
 * This is the concrete implementation of the BinarySearchTree.
 * 
 * @author aseem
 *
 * @param <E>
 */
public class BinarySearchTreeImpl<E extends Comparable<E>> implements BinarySearchTree<E>, Comparator<E> {
	
	//Initially the tree is empty and the root is pointing to null
	BinaryTreeNode<E> root = null;
	
	/*
	 * This is a custom comparator, it checks whether the value of node1 is bigger or the node2 is bigger,
	 * it plays key role in BST.
	 * (non-Javadoc)
	 * @see java.util.Comparator#compare(java.lang.Object, java.lang.Object)
	 */
	public int compare(E node1, E node2) {
		return node1.compareTo(node2);
	}
	
	/*
	 * It takes care all the edge cases and inserts a node in BST at the appropriate position.
	 * (non-Javadoc)
	 * @see in.logikx.datastructures.BinarySearchTree#insert(java.lang.Object)
	 */
	public void insert(E element) {
		BinaryTreeNode<E> temp = root;
		//Check if the tree is empty
		if(temp == null){
			temp = new BinaryTreeNode<E>();
			temp.value = element;
		}else{
			//element is smaller than root
			if(compare(temp.value,element) == 1){
				temp = temp.left;
				insert(element);
			}else{
				temp = temp.right;
				insert(element);
			}
		}		
	}

	/*
	 * This method helps to find the location of element we are searching for.
	 * (non-Javadoc)
	 * @see in.logikx.datastructures.BinarySearchTree#find(java.lang.Object, in.logikx.datastructures.BinaryTreeNode, in.logikx.datastructures.BinaryTreeNode)
	 */
	public void find(E item, BinaryTreeNode<E> location, BinaryTreeNode<E> parentLocation) {
		BinaryTreeNode<E> tempLocation = null;
		BinaryTreeNode<E> tempParentLocation = null;
		if(root == null){
			location = null;
			parentLocation = null;
			return;
		}
		if(root.getValue().compareTo(item) == 0){
			parentLocation = null;
			location = root;
			return;
		}
		if(root.getValue().compareTo(item) > 0){
			tempLocation = root.getLeft();
		}else{
			tempLocation = root.getRight();
		}
		tempParentLocation = root;
		while(tempLocation != null){
			if(item.compareTo(tempLocation.getValue()) == 0){
				location = tempLocation;
				parentLocation = tempParentLocation;
				return;
			}
			tempParentLocation = tempLocation;
			if(item.compareTo(tempLocation.getValue()) > 0){
				tempLocation = tempLocation.getRight();
			}else{
				tempLocation = tempLocation.getLeft();
			}
		}
		location = null;
		parentLocation = tempParentLocation;
	}
	
	/*
	 * (non-Javadoc)
	 * @see in.logikx.datastructures.BinarySearchTree#delete(java.lang.Object)
	 */
	@SuppressWarnings("unused")
	public void delete(E element) {
		BinaryTreeNode<E> location = null;
		BinaryTreeNode<E> parentLocation = null;
		if(root == null){
			//TODO throw an exception
			return;
		}
		find(element, location, parentLocation);
		if(location == null){
			//TODO throw an exception : Item is not present
			return;
		}
		if(location.getLeft() == null && location.getRight() == null){
			deleteCaseA(location, parentLocation);
		}else if(location.getLeft() != null && location.getRight() == null){
			deleteCaseB(location, parentLocation);
		}else if(location.getLeft() == null && location.getRight() != null){
			deleteCaseB(location, parentLocation);
		}else{
			deleteCaseC(location, parentLocation);
		}
		
	}
	
	/*
	 * (non-Javadoc)
	 * @see in.logikx.datastructures.BinarySearchTree#deleteCaseA(in.logikx.datastructures.BinaryTreeNode, in.logikx.datastructures.BinaryTreeNode)
	 */
	public void deleteCaseA(BinaryTreeNode<E> location, BinaryTreeNode<E> parentLocation) {
		if(parentLocation == null){
			root = null;
		}else{
			if(location == parentLocation.getLeft()){
				parentLocation.setLeft(null);
			}else{
				parentLocation.setRight(null);
			}
		}
		
	}
	
	/*
	 * (non-Javadoc)
	 * @see in.logikx.datastructures.BinarySearchTree#deleteCaseB(in.logikx.datastructures.BinaryTreeNode, in.logikx.datastructures.BinaryTreeNode)
	 */
	public void deleteCaseB(BinaryTreeNode<E> location, BinaryTreeNode<E> parentLocation) {
		BinaryTreeNode<E> onlyChild = null;
		if(location.getLeft() != null){
			onlyChild = location.getLeft();
		}else{
			onlyChild = location.getRight();
		}
		if(parentLocation == null){
			root = onlyChild;
		}else{
			if(location == parentLocation.getLeft()){
				parentLocation.setLeft(onlyChild);
			}else{
				parentLocation.setRight(onlyChild);
			}
		}
		
	}

	public void deleteCaseC(BinaryTreeNode<E> location, BinaryTreeNode<E> parentLocation) {
		// TODO Auto-generated method stub
		
	}
	
	/*
	 * (non-Javadoc)
	 * @see in.logikx.datastructures.BinarySearchTree#processCurrentNode(in.logikx.datastructures.BinaryTreeNode)
	 */
	public void processCurrentNode(BinaryTreeNode<E> currentNode) {
		//Do simple processing
		System.out.println(currentNode.getValue());
	}
	
	public void inorderTraversal(BinaryTreeNode<E> currentNode) {
		if(root == null){
			//TODO : exception that tree is empty
			return;
		}
		if(currentNode != null){
			inorderTraversal(currentNode.getLeft());
			processCurrentNode(currentNode);
			inorderTraversal(currentNode.getRight());
		}
	}
	
	/*
	 * (non-Javadoc)
	 * @see in.logikx.datastructures.BinarySearchTree#preOrderTraversal(in.logikx.datastructures.BinaryTreeNode)
	 */
	public void preOrderTraversal(BinaryTreeNode<E> currentNode) {
		if(root == null){
			//TODO : exception that tree is empty
			return;
		}
		if(currentNode != null){
			processCurrentNode(currentNode);
			preOrderTraversal(currentNode.getLeft());
			preOrderTraversal(currentNode.getRight());
		}
		
	}
	
	/*
	 * (non-Javadoc)
	 * @see in.logikx.datastructures.BinarySearchTree#postOrderTraversal(in.logikx.datastructures.BinaryTreeNode)
	 */
	public void postOrderTraversal(BinaryTreeNode<E> currentNode) {
		if(root == null){
			//TODO : exception that tree is empty
			return;
		}
		if(currentNode != null){
			postOrderTraversal(currentNode.getLeft());
			postOrderTraversal(currentNode.getRight());
			processCurrentNode(currentNode);
		}
		
	}

	
	public void getLCA(E element1, E element2) {
		// TODO Auto-generated method stub
		
	}

	public int getHeight() {
		// TODO Auto-generated method stub
		return 0;
	}

	public int getDiameter() {
		// TODO Auto-generated method stub
		return 0;
	}

	public int getMaxElement() {
		// TODO Auto-generated method stub
		return 0;
	}

	public int getMinElement() {
		// TODO Auto-generated method stub
		return 0;
	}
}
