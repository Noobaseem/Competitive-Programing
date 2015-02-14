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
#include <cstdlib>
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

struct  indexVal{
	int index;
	int value;
};

int myComaparator(const void* a, const void* b){
	int l = ((struct indexVal *) a)->index;
	int r = ((struct indexVal *) b)->index;
	return l-r;
}

int main(int argc, char* argv[]){
	struct indexVal arrayBasedOnIndex[5];
	//Create Array
	arrayBasedOnIndex[0].index = 3;
	arrayBasedOnIndex[0].value = 7;
	arrayBasedOnIndex[1].index = 2;
	arrayBasedOnIndex[1].value = 9;
	arrayBasedOnIndex[2].index = 7;
	arrayBasedOnIndex[2].value = 4;
	arrayBasedOnIndex[3].index = 1;
	arrayBasedOnIndex[3].value = 5;
	arrayBasedOnIndex[4].index = 8;
	arrayBasedOnIndex[4].value = 1;
	qsort(arrayBasedOnIndex, 5, sizeof(arrayBasedOnIndex[0]), myComaparator);
	for(int i = 0; i < 5; i++){
		cout<<arrayBasedOnIndex[i].value<<" ";
	}
	return 0;
}