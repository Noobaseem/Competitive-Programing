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
 
typedef long long int64;
using namespace std;
 
#define INF (1<<30)
#define N 1000001
 
char temp[N];
inline int sym(int n, int i){ return n-1-i; }
 
int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        gets(temp);
        int n = strlen(temp);
        int c = 1;
        
        for(int i=((n/2)-1); i >= 0; i--){
            if( temp[i] == temp[sym(n,i)] ){
            	continue;
            }
            else if (temp[i] > temp[sym(n,i)]){
            	c = 0;
            }
            else{
            	c = 1;
            }
            break;
        }
        
        int i = (n-1)/2;
        while( i >= 0 ){
            if( c && temp[i] == '9' ){
                temp[i] = temp[sym(n,i)] = '0';
                c = 1;
            } else {
                temp[i] += c;
                temp[sym(n,i)] = temp[i];
                c = 0;
            }
            i--;
        }
        if( c > 0 ){
            printf("1");
            int i = n-1;
            while(i--) printf("0");
            printf("1\n");
        } else {
            printf("%s\n", temp);
        }
    }
    return 0;
}  
