/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 	 Batch of 2014
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
#include <map>
 
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

typedef map<int, int>  mii;
typedef pair<int, int> pii;

int main(int argc, char* argv[]){
	int T;
	scanf("%d",&T);
	while(T--){
		long long int n,s;
		scanf("%lld",&n);
		scanf("%lld",&s);
		long long int count = 0;
		long long int sum = (n*(n+1))/2;
		while(1){
			if((count*(count+1))/2 < (sum-s)){
				count++;
			}else{
				break;
			}
		}
		printf("%lld\n",count);
	}
}