/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 	 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
 
using namespace std;
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
int main(int argc, char* argv[]){
	int T;
	scanf("%d", &T);
	while(T--){
		string sides[6];
		for0(i,6){
			cin>>sides[i];
		}
		if((sides[0] == sides[2] && sides[0] == sides[5])
		 ||(sides[0] == sides[3] && sides[0] == sides[5])
		 ||(sides[0] == sides[2] && sides[0] == sides[4])
		 ||(sides[0] == sides[3] && sides[0] == sides[4])
		 ||(sides[2] == sides[1] && sides[2] == sides[5])
		 ||(sides[2] == sides[4] && sides[2] == sides[1])
		 ||(sides[1] == sides[3] && sides[1] == sides[5])
		 ||(sides[1] == sides[3] && sides[1] == sides[4])){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
 
	}	
} 