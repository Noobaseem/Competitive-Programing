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
 
using namespace std;
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		long long int range = 0;
		long long int number;
		scanf("%lld",&number);
		long long int lowerlimit = 1;
		long long int upperlimit = 1;
		long long int count = 1;
		while(1){
			if(number >= lowerlimit && number <= upperlimit){
				break;
			}
			lowerlimit = upperlimit + 1;
			range += 1;
			upperlimit = lowerlimit + range;
			count += 1;
		}
		long long int upper = 1;
		for(long long int i = lowerlimit; i <= upperlimit; i++){
			if(number == i){
				cout<<"TERM "<<number<<" IS ";
				if(range%2 == 0){
					cout<<count<<"/"<<upper;
				}else{
					cout<<upper<<"/"<<count;
				}
				break;
			}
			upper++;
			count--;
		}
		cout<<"\n";
	}
	return 0;
} 
