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
 
using namespace std;
 
int main(){
    int g, b;
    scanf("%d%d", &g, &b);
    
    while(g != -1) {
        int G, B;
        G = max(g,b);
        B = min(g,b);
        
        int sol = G / (B+1) + (G % (B+1) > 0);
        printf("%d\n", sol);
        
        scanf("%d%d", &g, &b);
    }
    
    
    return 0;
} 
