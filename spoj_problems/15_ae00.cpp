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
	int number;
	int n;
	long long int totalRectangles = 0;
	scanf("%d",&number);
	n = abs(sqrt(number));
	for0(i,n){
		totalRectangles +=  number/(i+1);
	}
	long long int x = totalRectangles-(n*(n-1)/2);
	printf("%lld",x);
	return 0;
}
