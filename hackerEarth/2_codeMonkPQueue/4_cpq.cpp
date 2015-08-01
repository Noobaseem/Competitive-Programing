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

class compareDist{
	public:
    bool operator()(pair<int,int> n1,pair<int,int> n2){
 
      if(n1.second>n2.second)
      return true;
      else
      return false;
 
    }
};

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef priority_queue<pii, vii, compareDist> pqii;

int main(int argc, char* argv[]){
    int C, P, N;
    pii* px;
    cin>>C>>P>>N;
    int Y[N];
    int temp;
    int x[C][3];
    pqii q;
    for0(i,C){
    	x[i][0] = 0;
    	x[i][1] = 0;
    	x[i][2] = 0;
    	if(i < N) {
    		cin>>temp;
			x[i][0] = temp;
			x[i][2] = 1;
    	}
    	q.push(make_pair(i+1,x[i][0]*x[i][2]));
    }
    int jq;
    int key;
    for0(i,P){
    	px = (pii *)&q.top();
    	cin>>jq;
    	key = (int) px->first;
    	cout<<key<<" ";
    	x[key-1][1] = x[key-1][0];
    	x[key-1][0] = jq;
    	x[key-1][2]++;
    	int xs = x[key-1][0] + x[key-1][1];
    	q.pop();
    	q.push(make_pair(key,xs*x[key-1][2]));
    }
}