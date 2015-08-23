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
vi B;

void getKMax(int arr[], int n, int k) {
	std::deque<int> Qi(k);
	int i;
	for (i = 0; i < k; ++i) {	
		while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();

		Qi.push_back(i);
	}
	for ( ; i < n; ++i) {
		B.pb(arr[Qi.front()]);

		while ( (!Qi.empty()) && Qi.front() <= i - k)
			Qi.pop_front();

		while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();

		Qi.push_back(i);
	}
	B.pb(arr[Qi.front()]);
}

int main() {
	int N, M; si(N); si(M);
	int A[N]; int temp;
	for0(i,N){
		si(temp); A[i] = temp;
	}
	for0(i,N){
		int k = i+1;
		getKMax(A, N, k);
	}
	for0(i,M){
		vi C = B;
		char c,d;
		int p;
		cin>>c>>p>>d;
		char e = (d == 'D') ? 'C' : 'D';
		int count = 0;
		if(c == '>'){
			for0(i,(N*(N+1)/2)){
				if(C[i] > p) count++;
			}
			(count%2==0) ? cout<<e : cout<<d;
		}else if(c == '='){
			for0(i,(N*(N+1)/2)){
				if(C[i] == p) count++;
			}
			(count%2==0) ? cout<<e : cout<<d;
		}else{
			for0(i,(N*(N+1)/2)){
				if(C[i] < p) count++;
			}
			(count%2==0) ? cout<<e : cout<<d;
		}
	}
}