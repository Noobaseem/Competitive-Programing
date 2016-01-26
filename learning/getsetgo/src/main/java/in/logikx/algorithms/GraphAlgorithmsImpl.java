package in.logikx.algorithms;

import java.util.LinkedList;
import java.util.Stack;

import in.logikx.datastructures.AdjListElement;
import in.logikx.datastructures.GraphImpl;

/**
 * This contains the implementation of the major algorithms that we run on graphs
 * 
 * @author aseem
 *
 */
public class GraphAlgorithmsImpl implements GraphAlgorithms {
	
	LinkedList<AdjListElement>[] adjList;
	
	public void topologicalSortUtil(Stack sortedVertices, Boolean[] visited, int v){
		visited[v] = true;
		for(AdjListElement element : adjList[v]){
			if(!visited[element.getTarget()]){
				topologicalSortUtil(sortedVertices, visited, element.getTarget());
			}
			sortedVertices.push(v);
		}
	}
	
	/*
	 * This is the concrete implementation of topological sort, here we are assuming that node 0 has
	 * no incoming edges towards it.
	 * (non-Javadoc)
	 * @see in.logikx.algorithms.GraphAlgorithms#topologicalSort()
	 */
	public void topologicalSort(GraphImpl graph) {		
		adjList = graph.getAdjList();
		if(graph.isDirected()){
			Boolean[] visited = new Boolean[graph.getNNodes()];
			Stack<Integer> sortedVertices = new Stack<Integer>();
			for(Boolean status : visited) status = false;
			for(int i = 0; i < graph.getNNodes(); i++){
				if(!visited[i]){
					topologicalSortUtil(sortedVertices, visited, i);
				}
			}
			while(!sortedVertices.isEmpty()){
				System.out.print(sortedVertices.pop()+" ");
			}
		}else{
			//TODO : Throw an error that the graph is not directed
		}
	}

}
