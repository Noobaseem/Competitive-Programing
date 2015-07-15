/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 	 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
 
using namespace std;
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
long long int K[100005][505];
 
/*Useful notations*/
struct  indexVal{
	int be;
	int w;
};
 
long long int max(long long int a, long long int b) { return (a > b)? a : b; }
 
/*int myComaparator(const void* a, const void* b){
	int l = ((struct indexVal *) a)->be;
	int r = ((struct indexVal *) b)->be;
	return l-r;
}*/
 
long long int knapSack(int W, int wt[], int val[], int n) {
   int i, w;
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++) {
       for (w = 0; w <= W; w++) {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}	
 
int main(int argc, char* argv[]){
	int T;
	scanf("%d", &T);
	while(T--){
		int N, K, M;
		cin>>N>>K>>M;
		indexVal X[N];
		int B = 0;
		long long int sum = 0;
		int count = 0;
		int cal = 0;
		for0(i,N){
			scanf("%d", &B);
			sum += B;
			X[i].be = B;
			X[i].w = 201;
			if(B < 0) count++;	
		}
		for0(i,M){
			int L, R, C;
			cin>>L>>R>>C;
			for(int j = L-1; j < R; j++){
				if(C < X[j].w) X[j].w = C;
			}
		}
		//qsort(X, N, sizeof(X[0]), myComaparator);
		int val[count];
		int wt[count];
		for0(i,N){
			if(X[i].be < 0 && X[i].w != 201){
				val[cal] = -1*X[i].be;
				wt[cal] = X[i].w;
				cal++;
			}
		}
		/*for0(i,N){
			if(X[i].w != 201) {
				val[c] = -1*X[i].be;
				wt[c] = X[i].w;
				c++;
			}
		}*/
		if(cal){
			cout<<sum+knapSack(K, wt, val, cal)<<"\n";
		}else{
			cout<<sum<<"\n";
		}
	}	
}  