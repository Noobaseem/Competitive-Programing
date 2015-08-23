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
#define fora(i, a, n) for(int i = a; i <= n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

int main(int argc, char* argv[]){
    int T;
    si(T);
    while(T--){
    	int N, H, l, h; si(N); si(H);
    	int A[N];
    	for0(i,N) A[i] = N;
    	for0(i,N){
    		si(l); si(h);
    		fora(i,l,h) A[i]--;
    	}
    	int min = 0;
    	for0(i,H){
    		min += A[i];
    	}
    	int tempSoil = min;
    	for(int i = 1; i <= N-H; i++){
    		int h1 = (H-1)+i;
    		int s = A[h1];
    		int newVal = 	tempSoil-A[i-1]+s;
    		if(newVal < min) min = newVal;
    		tempSoil = newVal;
    	}
    	cout<<min<<endl;
    }
}