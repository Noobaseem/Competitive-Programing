/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
/*My utility functions*/
#define pb push_back
#define pf push_front
#define sz size

/*Input and output*/
#define si(n) scanf("%d",&n);
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

typedef priority_queue<int> pi;
typedef map<int, int> mi;

int main(int argc, char* argv[]){
	int M, N;
	cin>>M>>N;
	pi q;
	int t;
	for0(i,M){
		cin>>t;
		q.push(t);
	}
	int sum = 0, x;
	for0(i,N){
		x = q.top();
		sum += x;
		q.pop();
		q.push(x-1);
	}
	cout<<sum;
}