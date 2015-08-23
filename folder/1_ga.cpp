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

typedef priority_queue<int> pqi;

int main(int argc, char* argv[]){
    int T;
    si(T);
    while(T--){
    	pqi r;
    	int W,R;
    	string w, r1;
    	cin>>w;
    	cin>>r1;
    	for0(i,r1.size()){
    		r.push(-(int)r1[i]);
    	}
    	for0(i,w.size()){
    		if(!r.empty()){
    			if(-r.top()<(int)w[i]){
    				w[i] = (char)(-r.top());
    				r.pop();
    			}
    		}
    		cout<<w[i];
    	}
    	cout<<endl;
    }
}