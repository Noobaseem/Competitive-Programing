/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		     Batch of 2014
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
	float sum,k,t;
    int i;
    scanf("%f",&k);
    while(k!=0.00)
    {
        sum = 0;
        i = 1;
        while(sum<=k)
        {
            t=(float)1/(i+1);
            sum+=t;
            i++;
        }
        printf("%d card(s)\n",i-1);
        scanf("%f",&k);
    }
	return 0;
}
