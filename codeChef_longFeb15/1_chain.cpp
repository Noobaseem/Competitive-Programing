/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 	 Batch of 2014
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

/*Problem specific declarations*/
char availChars[2] = {'-','+'};

int main(int argc, char* argv[]){
	int T;
	scanf("%d", &T);
	while(T--){
		char input[100005];
		scanf("%s",&input);
		int length 	= strlen(input);
		int counter	= 0;
		int switches = 0, switchesRev = 0;
		char startWith  = '+';
		char startWith2 = '-';
		while(length--){
			if(input[counter] != startWith){
				switches++;
			}
			startWith = startWith == '+' ? '-' : '+';
			if(input[counter] != startWith2){
				switchesRev++;
			}
			startWith2 = startWith2 == '+' ? '-' : '+';
			counter++;
		}
		if(switches > switchesRev){
			printf("%d\n",switchesRev);
		}else{
			printf("%d\n",switches);
		}
	}
}