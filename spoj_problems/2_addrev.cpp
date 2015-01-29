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
 
int reverse(int x){
    int rev = 0;
    while(x>0){
        rev = rev*10 + x%10;
        x = x/10;
    }
    return rev;
}
 
int main(int argc, char* argv[]){
    int n;
    cin>>n;
    while(n){
        int a,b;
        cin>>a>>b;
        cout<<reverse(reverse(a)+reverse(b))<<"\n";
        n--;
    }
} 
