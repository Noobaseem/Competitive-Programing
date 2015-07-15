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
 
using namespace std;

/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)

#define MOD 1000000007

int getMid(int s, int e) {  return s + (e -s)/2;  }
 
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index) {
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return (((getSumUtil(st, ss, mid, qs, qe, 2*index+1))%MOD +
           (getSumUtil(st, mid+1, se, qs, qe, 2*index+2))%MOD)%MOD;
}
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index) {
    if (i < ss || i > se)
        return;
    st[index] = st[index] + diff;
    if (se != ss) {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
void updateValue(int arr[], int *st, int n, int i, int new_val) {
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

int getSum(int *st, int n, int qs, int qe) {
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  ((constructSTUtil(arr, ss, mid, st, si*2+1))%MOD +
              (constructSTUtil(arr, mid+1, se, st, si*2+2)%MOD))%MOD;
    return st[si];
}

int *constructST(int arr[], int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}
 
int main(int argc, char* argv[]){
	int N,Q;
	scanf("%d", &N);
	scanf("%d", &Q);
	int A[N];
	int temp = 0;
	char t;
	long long int sum = 0;
	long long int x = 0;
	for0(i,N){
		scanf("%d", &temp);
		A[i] = temp;
	}
	int *st = constructST(A, N);
	int l, r, v;
	while(Q--){
		cin>>t;
		switch(t){
			case '1':
				scanf("%d", &l);
				scanf("%d", &r);
				scanf("%d", &v);
				for(int i = l-1; i < r; i++){
					v = v%MOD;
					A[i] = A[i]%MOD;
					updateValue(A, st, N, i, (A[i]+v)%MOD);
				}
				break;
			case '2':
				scanf("%d", &l);
				scanf("%d", &r);
				scanf("%d", &v);
				for(int i = l-1; i < r; i++){
					v = v%MOD;
					A[i] = A[i]%MOD;					
					x = (v*A[i])%MOD;
					updateValue(A, st, N, i, x);
				}
				break;
			case '3':
				scanf("%d", &l);
				scanf("%d", &r);
				scanf("%d", &v);
				for(int i = l-1; i < r; i++){
					v = v%MOD;
					updateValue(A, st, N, i, v);
				}
				break;
			case '4':
				scanf("%d", &l);
				scanf("%d", &r);
				printf("%d\n", getSum(st, N, l-1, r-1));
				break;
		}
	}
}