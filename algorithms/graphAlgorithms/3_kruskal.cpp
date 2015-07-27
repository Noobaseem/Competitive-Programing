/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/

/*
	This program is the c++ implementation of the Kruskal's Algorithm. It is one of the most famous algorithm given by Joseph Bernard Kruskal Jr.’s
	The algorithm is mostly used to find the Minimum Spanning Tree in the given tree. It is based on greedy approach. Also note that there is
	one more algorithm named 'Prim's Algorithm' which can do all the things that Kruskal Algorithm can do. But in competitive programing we generally
	implement Kruskal Algorhithm because of it's simple logic and easy to code style. It only uses 2 dataitypes a) Priority Queues and b) Disjoint 
	Sets ADT.
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
/*My utility functions*/
#define pb push_back
#define pf push_front
#define sz size

/*Input and output*/
#define si(n) scanf("%d",&n);
#define pi(n) printf("%d",n);
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

/*Useful datastructures*/
typedef vector<int> vi;

/*Important declarations for the disjoin-union sets*/

vi parent;
vi weight;

void makeset(int size) {
    for0(i,size){
        parent.pb(i);
        weight.pb(1);
    }
}

/*Quick find with path compression*/
int qFind(int item){
    int newItem = item;
    int root    = item;
    /*Check if we have reached the root*/
    while(root != parent[root]){
        root = parent[root];
    }
    /*Apply path compression so that all child nodes point to the parent node*/
    while(item != root){
        newItem      = parent[item];
        parent[item] = root;
        item         = newItem; 
    }
    return root;
}

/*Quick union along with the weight heuristic*/
void qUnion(int item1, int item2, int & count){
    int l, r;
    l = qFind(item1);
    r = qFind(item2);
    /*If l and r belong to the same set then return*/
    if(l == r) return;
    /*Compare the weights of the roots nodes, make smaller root point to bigger root*/
    if(weight[l] < weight[r]){
        parent[l] = r;
        weight[r] += weight[l];
    }else{
        parent[r] = l;
        weight[l] += weight[r];
    }
    count--;
}

#define trAdj(c,it) for(vvii::iterator it = c.begin(); it != c.end(); it++)

/*
	Defining the concept of edgeList in order to implement the Kruskal's Algorithm
	It is nothing but the definition of the edge. With first parameter being the weight and 2nd paramenter being the to and from vertices
*/

typedef pair<int,int> pii;
typedef priority_queue<int, pii> pqii;

pqii edgeList(5);

int main(int argc, char* argv[]){

	/*Enter the number of vertices*/
	int N;
	si(N);

	/*Enter the number of edges*/
	int E;
	si(E);

    edgeList.resize(E);

    /*Fill the parent array*/
	makeset(N);

    /*
		Here 'w' is weight of the ith edge, which connects 'u' and 'v' vertices.
		The variable minCost keeps track of the minimum cost till now.
    */
    int W;
    int u,v;
    int minCost = 0;

    for0(i,E){
    	si(w); si(u); si(v);
    	//Here '-' sign before 'w' is applied in order to make priority queue store values in ascending order
    	edgeList.pb(-w,make_pair(u,v));
    }

    while(!edgeList.empty()){
    	pii front = edgeList.top();
    	edgeList.pop();
    	/*
			Include the current edge only if it does not lead to a cycle.
			In order to check that the edge is causing a cycle or not, we just need to check that the parent of the vertices,
			which the edge is connecting, are not same.
    	*/
    	if(qfind(front.second.first) != qFind(front.second.second)){
    		minCost += (-front.first);
    		qUnion(front.second.first,front.second.second);
    	}
    }

    cout<<minCost;
}