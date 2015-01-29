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
	while(1){
		int N;
		scanf("%d",&N);
		if(N == -1){
			break;
		}else{
			int candyPackets[N];
			int moves = 0;
			int counter = 0;
			int sum = 0;
			int candyPerPacket = 0;
			for0(i,N){
				scanf("%d",&candyPackets[i]);
				sum += candyPackets[i];
			}
			if(sum%N != 0){
				printf("-1\n");
			}else{
				candyPerPacket = sum/N;
				for0(i,N){
					if(candyPackets[i] < candyPerPacket){
						moves += candyPerPacket - candyPackets[i];
					}
				}
				printf("%d\n",moves);
			}
		}
	}
	return 0;
}
