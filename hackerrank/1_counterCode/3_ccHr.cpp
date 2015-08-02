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
	    	int N, M; si(N); si(M);
	    	vi A(N+1);
	    	for0(i,N) A[i] = 0;
	    	int a = 0,b = N-1;
	    	int x = 0, d = 0;
	    	if(N == 1){
	    		d = M-1;
	    		x = 1;
	    	}else if(N == 2){
	    		x = (M%2==0) ? 2 : 1;
	    		d = ((x == 1) ? (M/2) + 1 : M/2)-1; 
			}else{
				for0(i,M){
					if(N%2 == 0){
						if(i%2 != 0){
							if(i == M-1){
								x = b+1;
								d = A[b];
							}else{
								A[b] += 1;
								if(b == (N/2)){
									b = N-1;
								}else{
									b--;
								}
							}
						}else{
							if(i == M-1){
								x = a+1;
								d = A[a];
							}else{
								A[a] += 1;
								if(a == (N/2)-1){
									a = 0;
								}else{
									a++;
								}
							}
						}
					}else{
						if(i%2==0){
							if(i==M-1){
								x = a+1;
								d = A[a];
							}else{
								A[a] += 1;
								if(a == b){
									a = 0;
									b = N-1;
								}else{
									a++;
								}
							}
						}else{
							if(i==M-1){
								x = b+1;
								d = A[b];
							}else{
								A[b] += 1;
								if(a == b){
									a = 0;
									b = N-1;
								}else{
									b--;
								}
							}
						}
					}
	    		}
			}
			cout<<x<<" "<<d<<endl;
	    }
	}