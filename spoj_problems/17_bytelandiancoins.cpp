/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		     Batch of 2014
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
 
typedef map<int, long long int> mapper;
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
 
mapper map1;
 
long long int dynamicChain(long long int n){
    if(n == 0){
        return 0;
    }
	
	if(map1[n] != 0){
		return map1[n];
	}
	
	long long int temp = dynamicChain(n/2) + dynamicChain(n/3) + dynamicChain(n/4);
	
	if(temp > n){
		map1[n] = temp;
	}else{
		map1[n] = n;
	}
	return map1[n];
	
}
 
int main(int argc, char* argv[]){
	int T = 10;
	while(T){
	    long long int n;
	    scanf("%lld", &n);
	    printf("%lld\n", dynamicChain(n));
        T--;
	}
	return 0;
}
