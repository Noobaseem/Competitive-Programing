package in.logikx.datastructures;

/**
 * This abstract class is a basic reprentation of a Graph. It contains common features that every graph structures requires.
 * Each graph can be categorised as a directed/un-directed, further each graph contains a set of nodes. The number of nodes
 * and the directed/undirected property are determined at the time of it's instantitation. The nodes of the graph are labelled
 * by integeres 0,1,..,(n-1) where n is the number of nodes in the graph. Initially the graph does not contain any edge, but
 * it supports methods such as addition and deletion of edges.
 * 
 * @author aseem
 *
 */
public abstract class Graph {
	
	protected int nNodes;
	protected boolean directed;
	
	public Graph(int nodes, boolean directed){
		this.nNodes = nodes;
		this.directed = directed;
	}
	
	public int getNNodes(){
		return this.nNodes;
	}
	
	public boolean isDirected(){
		return this.directed;
	}
	
	/**
	 * 
	 * @param source
	 * @param target
	 * @param weight
	 */
	public abstract void addEdge(int source, int target, int weight);
	
	/**
	 * 
	 * @param source
	 * @param target
	 * @param weight
	 */
	public abstract void addEdgeSafe(int source, int target, int weight);
	
	public abstract void addEdge(Edge e);
	
	public abstract void addEdgeSafe(Edge e);
	
	public abstract void removeAllEdges();
	
	public abstract void removeEdge(int source, int edge);
	
	public abstract void getWeightOfEdge(int source, int edge);
}
