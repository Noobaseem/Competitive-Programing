/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 	 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/

/*
	This the dynamic programing implementatin of longest common subsequence problem
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

char X[1024];
char Y[1024];

int dp[1024][1024];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int lcs(int m, int n) {
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
			}else{
				dp[i][j] = (X[i-1] == Y[j-1]) ? (1+dp[i-1][j-1]) : max(dp[i-1][j], dp[i][j-1]);
			}			
		}
	}
	return dp[m][n];
}

int main(int argc,char* argv[]) {
	scanf("%s",&X);
	scanf("%s",&Y);
	int m = strlen(X);
	int n = strlen(Y);
	cout<<lcs(m,n);
	return 0;
}