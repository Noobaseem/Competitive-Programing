/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/
 
#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
/*My utility functions*/
#define pb push_back
#define pf push_front
#define sz size
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
 
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		long long int a, b, n, ax, d;
		scanf("%lld %lld %lld", &a, &b, &n);
		long long int s = (2*n/(a+b));
		printf("%lld\n", (2*n/(a+b)));
		d = (b-a)/(s-5);
		ax = a-2*d;
		
		for0(i,s) {
			printf("%lld",(ax+i*d));
	   		printf(" ");
	  	}
	  	cout<<"\n";
	}
	return 0;
} 
