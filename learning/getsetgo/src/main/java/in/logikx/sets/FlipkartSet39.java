package in.logikx.sets;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

import in.logikx.*;
import in.logikx.companies.CompanyNames;

/**
 * This is the geeksforgeeks set number 39 in the flipkart archives
 * 
 * @author aseem
 *
 */
public class FlipkartSet39 extends PreparationSet {
	
	SetDetails thisSet = new SetDetails();
	
	public void runSet(){
		buildSet();
		
	}
	
	public void runQuestion1(){
		
	}
	
	public void buildSet(){
		thisSet.setCompanyName(CompanyNames.FLIPKART);
		thisSet.setSetNumber("39");
		thisSet.setSetURI("http://www.geeksforgeeks.org/flipkart-interview-experience-set-39/");
	}
}

class FlipkartSet39Employee implements Comparable<FlipkartSet39Employee> {
	
	private Integer employeeId;
	private String Name;
	private int performanceRating;
	private int salary;
	List<FlipkartSet39Employee> juniors;
	List<FlipkartSet39Employee> toBeRemoved;
	PriorityQueue<FlipkartSet39Employee> potentialJuniorsToBeRemoved;
	private int salarySaved = 0;
	
	
	public Integer getEmployeeId() {
		return employeeId;
	}
	
	public void setEmployeeId(Integer employeeId) {
		this.employeeId = employeeId;
	}
	
	public String getName() {
		return Name;
	}
	
	public void setName(String name) {
		Name = name;
	}
	
	public int getPerformanceRating() {
		return performanceRating;
	}
	
	public void setPerformanceRating(int performanceRating) {
		this.performanceRating = performanceRating;
	}
	
	public int getSalary() {
		return salary;
	}
	
	public void setSalary(int salary) {
		this.salary = salary;
	}
	
	public void addJunior(FlipkartSet39Employee employee){
		this.getJuniors().add(employee);
	}
	
	public List<FlipkartSet39Employee> getJuniors(){
		return this.juniors;
	}
	
	public void addToBeRemoved(FlipkartSet39Employee employee){
		if(this.potentialJuniorsToBeRemoved.size() == 2){
			FlipkartSet39Employee e = this.potentialJuniorsToBeRemoved.peek();
			if(e.compareTo(employee) == -1){
				this.potentialJuniorsToBeRemoved.poll();
				this.potentialJuniorsToBeRemoved.add(employee);
				this.salarySaved = this.salarySaved - e.getSalary() + employee.getSalary(); 
			}
		}
		this.getToBeRemoved().add(employee);
	}
	
	public List<FlipkartSet39Employee> getToBeRemoved(){
		return this.toBeRemoved;
	}
	
	/*
	 * This method tells the PriorityQueue on what basis the listing should be maintained
	 * (non-Javadoc)
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	public int compareTo(FlipkartSet39Employee o) {
		if(this.getPerformanceRating() > o.getPerformanceRating()){
			return 1;
		}else if(this.getPerformanceRating() > o.getPerformanceRating()){
			return -1;
		}else{
			if(this.getSalary() > o.getSalary()){
				return 1;
			}else{
				return -1;
			}
		}
	}
}