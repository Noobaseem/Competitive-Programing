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
#include <cmath>
 
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
 
int main(int argc, char* argv[]){
	int t, N, i;
	long long int array[ 1000000 ], sum;
	scanf( "%d", &t );
	while (t) {
		scanf( "%d", &N );
		for( i = 0; i < N; ++i ) {
			scanf( "%lld", array + i );
		}
		sum = 0;
		for ( i = 0; i < N; ++i ) {
			sum = ( sum + array[ i ] ) % N;
		}
		if ( sum == 0 ) {
			printf( "YES\n" );
		}
		else {
			printf( "NO\n" );
		}
		--t;
	}
	return 0;
}

