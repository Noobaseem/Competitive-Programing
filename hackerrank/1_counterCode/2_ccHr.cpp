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
    int T;
    si(T);
    while(T--){
    	int N;
    	si(N);
    	vi B(N);
    	int a = 1;
    	int b = N;
    	for0(i,N){
    		if(i%2 == 0){
    			B[i] = b;
    			b--;
    		}else{
    			B[i] = a;
    			a++;

    		}
    	}
    	for(int i = N-1; i >= 0; i--){
    		cout<<B[i]<<" ";
    	}
    	cout<<endl;
    }
}