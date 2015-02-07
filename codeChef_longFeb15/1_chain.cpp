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

char expectedChar(char current){
	return (current == availChars[0] ? availChars[1] : availChars[0]);
}

int main(int argc, char* argv[]){
	int T;
	scanf("%d", &T);
	while(T--){
		char input[100005];
		scanf("%s",&input);
		char inputCopy[100005];
		strcpy(inputCopy, input);
		char next, nextRev, expected, expectedRev;
		int length 	= strlen(input);
		int counter	= 0;
		int switches = 0, switchesRev = 0;
		while(length--){
			expected 	= expectedChar(input[counter]);
			expectedRev = expectedChar(inputCopy[length-1]); 
			if(strlen(input) == 1){
				break;
			}
			if(counter <= strlen(input)-2){
				next 	= input[counter+1];
				nextRev = inputCopy[length-2];
				
				if(next == expected){
					//do nothing
				}else{
					switches++;
					input[counter+1] = expected;
				}
	
				if(nextRev == expectedRev){
					//Do nothing
				}else{
					switchesRev++;
					inputCopy[length-2] = expectedRev;
				}
			}
			counter++;
		}
		if(switches > switchesRev){
			printf("%d\n",switchesRev);
		}else{
			printf("%d\n",switches);
		}
	}
}