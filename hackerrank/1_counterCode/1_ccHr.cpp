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

typedef vector<int> vi;

int main(int argc, char* argv[]){
    int N, K;
    si(N); si(K);
    vi A(N);
    for0(i,N) A[i] = 0;
    int r;
    for0(i,K){
    	si(r);
    	A[r-1] = 1;
    }
    int count = 0;
    for0(i,N){
    	if(A[i] != 1){
    		if(i == 0){
	    		if(A[i+1] != 1){
	    			A[i] = 1;
	    			count++;
	    		}
	    	}else if(i > 0 && i < N-1){
	    		if(A[i-1] != 1 && A[i+1] != 1){
	    			A[i] = 1;
	    			count++;
	    		}
	    	}else if(i == N-1){
	    		if(A[i-1] != 1){
	    			A[i] = 1;
	    			count++;
	    		}
	    	}
    	}
	    	
    }
    cout<<count+K;
}