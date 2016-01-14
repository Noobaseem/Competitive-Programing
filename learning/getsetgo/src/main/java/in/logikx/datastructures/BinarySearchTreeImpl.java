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

	public void delete(E element) {
		// TODO Auto-generated method stub
		
	}
	
	public void getLCA(E element1, E element2) {
		// TODO Auto-generated method stub
		
	}

	public int getHeight(BinaryTreeNode<E> root) {
		// TODO Auto-generated method stub
		return 0;
	}

	public int getDiameter(BinaryTreeNode<E> root) {
		// TODO Auto-generated method stub
		return 0;
	}

	public int getMaxElement(BinaryTreeNode<E> root) {
		// TODO Auto-generated method stub
		return 0;
	}

	public int getMinElement(BinaryTreeNode<E> root) {
		// TODO Auto-generated method stub
		return 0;
	}

	public int compare(E node1, E node2) {
		return node1.compareTo(node2);
	}

}
