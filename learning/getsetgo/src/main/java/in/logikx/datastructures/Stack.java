package in.logikx.datastructures;

import java.util.Arrays;
import in.logikx.services.PreparationConstants;

/**
 * This is a generic implementation of the stack class.
 * 
 * @author aseem
 *
 * @param <T>
 */
public class Stack<T> {
	
	private int size = 0;
	private int DEFAULT_CAPACITY = PreparationConstants.STACK_SIZE;
	private Object elements[];
	T top = null;
	
	//Constructor to initialize the elements array
	public Stack(){
		elements = new Object[DEFAULT_CAPACITY];
	}
	
	public void push(T element){
		if(size == elements.length){
			fixCapacity();
		}
		elements[size++] = element;
	}
	
	@SuppressWarnings("unchecked")
	public T pop(){
		T element = (T) elements[--size];
		elements[size] = null;
		return element;
	}

	//We can check the value at the top of the stack in O(1) time using this method
	public T getTop() {
		return top;
	}
	
	private void fixCapacity(){
		int newSize = elements.length*2;
		elements = Arrays.copyOf(elements, newSize);
	}
	
}
