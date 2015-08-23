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
#define sc(n) scanf("%c",&n);
#define sl(n) scanf("%ld",&n);
 
/*My personalised flavour of some c++ +constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

typedef map<long int, int> mlip; 
typedef vector<long int> vi;
vi A;
mlip mp;

int main(int argc, char* argv[]){
    int N,M; si(N); si(M);
    long int K, temp;
    for0(i,N){
    	sl(K); A.pb(K);
    	mp[K]++;
    }
    long long int i, j, p, ind;
    if(N>1){
    	i = 0;
    	j = 1;
    	p = (N*(N+1))/2;
    	ind = N;
    	int count = N, count1 = 1;
    	ind = N;
    	while(j < p){
    		temp = (A[i]>A[j])?A[i]:A[j];
    		A.pb(temp);
    		mp[A[ind]]++;
    		ind++;
    		i++;
    		j++;
    		count1++;
    		if(count1 == count){
    			count--;
    			count1=1;
    			i++;
    			j++;
    		}
    	}
    }
    char s, n, nc;
    int size = mp.size();
    long int count=0;
    for0(i,M){
    	cin>>s>>K>>n;
    	if(n=='D'){
    		nc = 'C';
    	}else{
    		nc = 'D';
    	}
    	mlip::iterator itr;
    	if(s == '>'){
    		if(mp.find(K) != mp.end()){
	    		itr = mp.find(K);
	    		itr++;
	    		for(; itr != mp.end(); itr++){
	    			count += (*itr).second;
	    		}
    		}
    	}else if(s == '='){
    		count = mp[K];
    	}else{
    		if(mp.find(K) != mp.end()){
	    		itr = mp.find(K);
	    		for(mlip::iterator it = mp.begin(); it != itr; it++){
	    			count += (*it).second;
	    		}
    		}
    	}
    	if(count%2==0){
    		printf("%c",nc);
    	}else{
    		printf("%c",n);
    	}
    	count = 0;
    }
}