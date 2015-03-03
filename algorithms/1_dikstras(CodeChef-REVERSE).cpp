/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 	 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/
 
#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <functional>
 
using namespace std;
 
/*My utility functions*/
#define pb push_back
#define pf push_front
#define mp make_pair
#define sz size
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
 
class compareDist{
	public:
    bool operator()(pair<int,int> n1,pair<int,int> n2){
 
      if(n1.second<n2.second)
      return true;
      else
      return false;
 
    }
};
 
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef multimap<int,pii> mip;
typedef vector<int> vi;
typedef vector<char> vc;
typedef priority_queue<pii, vii, compareDist> pqii;
 
int main(int argc, char* argv[]){
 
	/*Defining variable used in the probelm*/
	int N,M;
	int X,Y;
	vi distance;
	vc visited;
	vi v;
	mip adjacencyList;
	pqii myQueue;
	
	scanf("%d %d", &N, &M);
	
	/*Creating an adjacency list for the graph*/
	for0(i, N){
		scanf("%d %d", &X, &Y);
		adjacencyList.insert(mp(X,mp(Y,0)));
		adjacencyList.insert(mp(Y,mp(X,1)));
	}
	
	/*Applying Dijkstras Algorithm on the weighted graph*/
	for0(i, M){
		/*initializing the distace and visited vectors as per conditions*/
		if(i == 0){
			distance.pb(0);
			visited.pb('v');
		}else{
			distance.pb(-1);
			visited.pb('n');
		}
	}
	
	/*Inserting the source node in the queue*/
	myQueue.push(mp(1,0));
	
	/*The main queue steps for filling the vectors*/
	while(!myQueue.empty()){
		pii currentNode = myQueue.top();
		myQueue.pop();
		pii *p= (pii *)&(myQueue.top());
		mip::iterator it;
		for(mip::iterator it = adjacencyList.lower_bound(currentNode.first); it != adjacencyList.upper_bound(currentNode.first); it++){
			//cout<<it->second.first;
			/*Inserting new elements in priority queue*/
			int newDistance = distance[currentNode.first-1] + it->second.second;
			if(distance[it->second.first - 1] == -1){
				distance[it->second.first -1] = newDistance;
				myQueue.push(mp(it->second.first, newDistance));
			}
			/*Updating the priority queue*/
			if(distance[it->second.first -1] > newDistance){
				for(unsigned int i = 0; i < myQueue.size(); i++){
					if(p[i].first == (it->second.first -1)){
						p[i].second = newDistance;
					}
				}
			}
		}
	}
	cout<<distance[N-1]-1;
	return 0;
} 