package in.logikx.algorithms;

/**
 * 
 * @author aseem
 *
 */
public class SortingAlgorithmsImpl implements SortingAlgorithms {
	
	/*
	 * This is a private utility method used by the mergeSort algorithm
	 */
	private void merge(Object[] arrayToSort, int lowerIndex, int mid, int upperIndex) {
		// TODO Auto-generated method stub
		Object[] leftArray = new Object[mid-lowerIndex+1];
		Object[] rightArray = new Object[upperIndex-mid+1];
		for(int i = lowerIndex; i <= mid; i++){
			leftArray[i-lowerIndex] = arrayToSort[i];
		}
		for(int i = mid+1; i <= upperIndex; i++){
			rightArray[i-mid] = arrayToSort[i];
		}
		int left = 0;
		int right = 0;
		for(int i = lowerIndex; i < upperIndex; i++){
			if((Integer)leftArray[left] < (Integer)rightArray[right]){
				arrayToSort[i] = leftArray[left];
				left++;
			}else{
				arrayToSort[i] = rightArray[right];
				right++;
			}
		}
	}
	
	/*
	 * This is the implementation of the Classic MergeSort
	 * (non-Javadoc)
	 * @see in.logikx.algorithms.SortingAlgorithms#MergerSort()
	 */
	public void mergeSort(Object[] arrayToSort, int lowerIndex, int upperIndex) {
		// TODO Auto-generated method stub
		if(lowerIndex < upperIndex){
			int mid = lowerIndex + (upperIndex-lowerIndex)>>2;
			mergeSort(arrayToSort, lowerIndex, mid);
			mergeSort(arrayToSort, mid+1, upperIndex);
			merge(arrayToSort, lowerIndex, mid, upperIndex);			
		}
	}

	/*
	 * This is the implementation of the Classic QuickSort Algorithm
	 * (non-Javadoc)
	 * @see in.logikx.algorithms.SortingAlgorithms#QuickSort()
	 */
	public void quickSort(Object[] arrayToSort) {
		// TODO Auto-generated method stub
		
	}

}
