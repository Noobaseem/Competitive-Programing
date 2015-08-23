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
#define si(n) scanf("%lld",&n);
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

int main(int argc, char* argv[]){
    int T;
    si(T);
    while(T--){
    	long long int N; si(N);
    	long long int a = 2, b=3, x=3;
    	long long int c = 3;
    	if(N<=3){
    		cout<<N<<endl;
    	}else if(N==4){
    		cout<<3<<endl;
    	}else{
			while((a+b) <= N){
				c++;
				x = a+b;
				a = b;
				b = x;
			}
			cout<<c<<endl;
    	}
    }
}