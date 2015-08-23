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

using namespace std;

typedef vector<long long int> vll;
vll t, lazy;

long long int query(long int node, int a, int b, int i, int j)
{
	if(a>b||a>j||b<i) return 0;
	if (lazy[node] !=0 ) {
		t[node]+=lazy[node]*(b-a+1);
		if (a!=b) {
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	
	if (a>=i && b<=j) return t[node];
	
	long long int q1=query(node*2, a, (a+b)/2, i, j);
	long long int q2=query(node*2+1, (a+b)/2+1, b, i, j);
	
	return q1+q2;
}

void update(int node, int a, int b, int i, int j, int inc) {
	if(a>b) return;
	if (lazy[node]!=0) {
		t[node]+=lazy[node]*(b-a+1);
		if (a!=b) {
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(a>b||a>j||b<i) return;
	
	if (a>=i && b<=j) {
		t[node]+=inc*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=inc;
			lazy[node*2+1]+=inc;
		}
		return;
	}
	
	update(node*2, a, (a+b)/2, i, j, inc);
	update(node*2+1, (a+b)/2+1, b,i, j, inc);
	t[node] = t[node*2] + t[node*2+1];
}

int main(int argc, char* argv[]){
	int T; si(T);
	int N, H, a, b;
	while(T--){
		si(N); si(H);
		long int x = (int)(ceil(log2(N)));
    	long int max_size = 2*(int)pow(2, x)+5;
    	t.resize(max_size); lazy.resize(max_size);
    	for0(i,N){
    		si(a); si(b);
    		update(1, 0, N-1, a, b, 1);
    	}
    	long long int min = query(1, 0, N-1, 0, H-1), temp;
    	fora(i,1,N-H+1){
    		temp = query(1, 0, N-1, i, i+H-1);
    		if(min<temp) min=temp;
    		if(min==(long long int)N*(long long int)H) break;
    	}
    	cout<<(long long int)((long long int)N*(long long int)H)-min<<endl;
    	t.clear(); lazy.clear();
	}
}