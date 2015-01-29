#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int sortWay (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}
 
int main(){
	int T;
	scanf("%d",&T);
	while(T){
		int N;
		scanf("%d",&N);
		int man[N];
		int woman[N];
		for( int i = 0; i < N; i++ ){
			scanf("%d",&man[i]);
		}
		for( int i = 0; i < N; i++ ){
			scanf("%d",&woman[i]);
		}
		qsort (man, N, sizeof(int), sortWay);
		qsort (woman, N, sizeof(int), sortWay);
		int sum = 0;
		for(int i = 0; i < N; i++){
			sum+=man[i] *woman[i];
		}
		cout<<sum<<"\n";
		T--;
	}
	return 0;
} 
