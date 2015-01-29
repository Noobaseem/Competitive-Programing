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
 
int main(int argc, char* argv[]){
    int t;
    cin>>t;
    while(t){
        long int n=0, count=0, j;
        cin>>n;
        count = n/5;
        for( j = 25; n/j > 0; j *= 5 ){
            count += n/j;
        }
        cout<<count<<"\n";
        t--;
    }
    return 0;
} 
Close
