package in.logikx.runapplication;

import java.util.PriorityQueue;

/**
 * This is the playground where i evaluate each of my code.
 * 
 * @author aseem
 *
 */
public class Learning {
	
	public void go(){
		/*
		 * This is the place where the things get started
		 */
		A a = new A();
		a.setValue(1);
		a.setName("z");
		A b = new A();
		b.setValue(2);
		b.setName("y");
		PriorityQueue<A> pq = new PriorityQueue<A>();
		pq.add(a);
		pq.add(b);
		System.out.println(pq.peek().name);
	}
	
	public static void main(String[] args) {
		Learning learn = new Learning();
		learn.go();
	}

}

class A implements Comparable<A>{
	
	int value;
	String name;
	
	public int getValue() {
		return value;
	}
	public void setValue(int value) {
		this.value = value;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int compareTo(A o) {
		return (this.getValue() > o.getValue()) ? 1 : -1;
	}	
}
