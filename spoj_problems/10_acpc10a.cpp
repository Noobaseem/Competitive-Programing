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
		int a,b,c;
		cin>>a>>b>>c;
		if( a == 0 && b == 0 && c == 0 ){
			break;
		}else{
			if( b-a == c-b ){
				cout<<"AP "<<c+(c-b);
			}else{
				cout<<"GP "<<c*c/b;
			}
		}
		cout<<"\n";
	}
	return 0;
}
