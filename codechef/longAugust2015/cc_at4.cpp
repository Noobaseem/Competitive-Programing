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
    	int N, H; si(N); si(H);
    	int length = N-H+1;
    	long long int Prod = N*H, min, arr[length];
    	for0(i,length) arr[i] = Prod;
    	min = Prod;
    	int l, h, low, high;
    	for0(i,N){
    		si(l); si(h);
    		low  = ((l-H+1)<0)?0:(l-H+1);
    		high = (h>length-1)?length:h;
    		fora()
    	}
    }
}