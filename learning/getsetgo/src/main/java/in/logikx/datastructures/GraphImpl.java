package in.logikx.datastructures;

import java.util.LinkedList;

/**
 * 
 * 
 * @author aseem
 *
 */
public class GraphImpl extends Graph {
	
	private LinkedList<AdjListElement>[] adjcList;
	
	/**
	 * This is the constructor for the Graph implementation
	 * 
	 * @param nodes
	 * @param directed
	 */
	public GraphImpl(int nodes, boolean directed) {
		super(nodes, directed);
		
		adjcList = new LinkedList[nodes];
		for(int i = 0; i < nodes; i++){
			adjcList[i] = new LinkedList<AdjListElement>();
		}
	}
	
	/**
	 * 
	 */
	public void addEdge(int source, int target, int weight) {
		AdjListElement element = new AdjListElement(target, weight);
		AdjListElement undirectedElement = new AdjListElement(source, weight);
		adjcList[source].add(element);
		if(!this.isDirected()){
			adjcList[target].add(undirectedElement);
		}
	}
	
	/**
	 * 
	 */
	public void addEdgeSafe(int source, int target, int weight) {
		boolean edgeAlreadyExists = false;
		AdjListElement listElement = new AdjListElement(target, weight);
		AdjListElement listElementUndirected = new AdjListElement(source, weight);
		if(source > this.getNNodes() || target > this.getNNodes()){
			//TODO : Throw an exception
			return;
		}
		//Check if the edge already exists in linked list
		for(AdjListElement element : adjcList[source]){
			if(element.getTarget() == target){
				edgeAlreadyExists = true;
			}
		}
		if(!this.isDirected() && !edgeAlreadyExists){
			for(AdjListElement element : adjcList[target]){
				if(element.getTarget() == source){
					edgeAlreadyExists = true;
				}
			}
		}
		if(edgeAlreadyExists){
			//TODO : throw an exception
		}else{
			adjcList[source].add(listElement);
			if(!this.isDirected()){
				adjcList[target].add(listElementUndirected);
			}
		}
	}

	public void addEdge(Edge e) {
		// TODO Auto-generated method stub
		
	}

	public void addEdgeSafe(Edge e) {
		// TODO Auto-generated method stub
		
	}

	public void removeAllEdges() {
		// TODO Auto-generated method stub
		
	}

	public void removeEdge(int source, int edge) {
		// TODO Auto-generated method stub
		
	}

	public void getWeightOfEdge(int source, int edge) {
		// TODO Auto-generated method stub
		
	}
}
