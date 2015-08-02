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
#define for0(i, n) for(long int i = 0; i < n; i++)
#define fora(i, a, n) for(long int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

typedef list<long long int> li;

int main(int argc, char* argv[]){
    long long int N; si(N);
    li P;
    long long int a;
    for0(i,N){
    	si(a); P.pb(a);
    }
    long long int x = 1;
    long long int days = 0;
    long long int c,p;
    while(x){
    	p = 1000000001;
    	x = 0;
    	for(li::iterator it = P.begin(); it != P.end(); it++){
    		c = *it;
    		if(c > p){
    			x = 1;
    			P.erase(it);
    			--it;
    		}
    		p = c;
    	}
    	if(x) days++;
    }
    cout<<days;
}