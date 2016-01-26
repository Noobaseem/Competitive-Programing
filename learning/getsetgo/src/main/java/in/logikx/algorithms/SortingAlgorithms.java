package in.logikx.algorithms;

/**
 * The major sorting algorithms that are used in Computer Science
 * 
 * @author aseem
 *
 */
public interface SortingAlgorithms {
	
	public void mergeSort(Object[] arrayToSort, int lowerIndex, int upperIndex);
	
	public void quickSort(Object[] arrayToSort);
}
