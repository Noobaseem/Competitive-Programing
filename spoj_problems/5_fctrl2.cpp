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
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )
 
int main(int argc, char* argv[]){
 
    int factorial[200];
    int m = 1;
    factorial[0] = 1;
    int temp = 0;
    int carry = 0;
    int t;
    cin>>t;
    while(t){
        factorial[0] = 1;
        temp = 0;
        m = 1;
        int n;
        cin>>n;
        for(int j = 1; j <= n; j++){
            for0(i,m){
                carry = factorial[i]*j + temp;
                factorial[i] = carry%10;
                temp = carry/10;
            }
            while(temp>0){
                factorial[m] = temp%10;
                temp = temp/10;
                m++;
            }
        }
        for( int i = m -1; i >=0 ; i-- ){
            cout<<factorial[i];
        }
        cout<<"\n";
        t--;
    }
    for0(i,m){
 
    }
 	return 0;
}
