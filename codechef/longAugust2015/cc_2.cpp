/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
/*My utility functions*/
#define pb push_back
#define pf push_front
#define sz size

/*Input and output*/
#define si(n) scanf("%d",&n);
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )


int main(int argc, char* argv[]){
    int T;
    si(T);
    while(T--){
    	string l1, l2;
    	cin>>l1;
    	cin>>l2;
    	int j1=0,j2=0,flag=0,flag2=0;
    	char temp1, temp2;
    	if(l1.at(0) == '.'){
    		flag = 1;
    		for0(i,l1.size()-1){
    			if(j1%2==0){
    				temp1 = l1.at(i+1);
    				temp2 = l2.at(i+1);
    			}else{
    				temp2 = l1.at(i+1);
    				temp1 = l2.at(i+1);
    			}
    			if(temp1 == '#' && temp2 == '#'){
    				flag = 0;
    				break;
    			}
    			if(temp1 == '#' && temp2 == '.'){
    				j1++;
    			}
    		}
    	}
    	if(l2.at(0) == '.'){
    		flag2=1;
    		for0(i,l1.size()-1){
    			if(j2%2==0){
    				temp1 = l2.at(i+1);
    				temp2 = l1.at(i+1);
    			}else{
    				temp2 = l2.at(i+1);
    				temp1 = l1.at(i+1);
    			}
    			if(temp1 == '#' && temp2 == '#'){
    				flag2 = 0;
    				break;
    			}
    			if(temp1 == '#' && temp2 == '.'){
    				j2++;
    			}
    		}
    	}
    	if(flag == 0 && flag2 == 0) cout<<"No"<<endl;
    	else if(flag == 0 && flag2 == 1) cout<<"Yes\n"<<j2<<endl;
    	else if(flag == 1 && flag2 == 0) cout<<"Yes\n"<<j1<<endl;
    	else{
    		if(j1>j2){
    			cout<<"Yes\n"<<j2<<endl;
    		}else{
    			cout<<"Yes\n"<<j1<<endl;
    		}
    	}
    }
}