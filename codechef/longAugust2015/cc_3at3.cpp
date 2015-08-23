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
    	int A[N], B[N], C[N];
        int min = 0;
    	memset(A, 0, N); memset(B, 0, N); memset(C, 0, N);
    	for0(i,N){
    		si(l); si(h);
    		for0(i,N){
                if(i >= l && i <= j){
                    A[i] = i+1;
                }
                if(i > 0){
                    B[i] = A[i]+A[i-1];
                }
                if(i > H-1){
                    C[i] = (B[i]+B[i-1]-B[H-i]);
                    if(min < C[i]) min = C[i];
                }else{
                    if(i>0) C[i] = B[i]+B[i-1];
                    if(min < C[i]) min = C[i];
                }
            }
    	}
    	cout<<N-min<<endl;
    }
}