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

typedef priority_queue<int> pqi;

int main(int argc, char* argv[]){
    int T;
    si(T);
    while(T--){
    	pqi pmax,pmin;
    	int N; si(N);
    	int temp;
    	long long int max = 1;
    	long long int min = 1;
    	long long int maxpos = 1, maxzer = 1, maxneg = 1;
    	long long int minpos = 1, minneg = 1;
    	int flag1 = 0, flag2 = 0, flag3 = 0;
    	int flag4 = 0, flag5 = 0, flag6 = 0;
    	for0(i,N){
    		cin>>temp;
    		pmax.push(temp);
    		pmin.push(temp);
    	}
        while(!pmax.empty() && pmax.top()>0){
    		maxpos *= pmax.top();
    		pmax.pop();
    		flag1 = 1;
    	}
    	while(!pmax.empty() && pmax.top()==0){
    		maxzer = 0;
    		pmax.pop();
    		flag2 = 1;
    	}
    	if(pmax.size()%2==0){
    		while(!pmax.empty()){
    			maxneg *= pmax.top();
    			pmax.pop();
    			flag3 = 1;
    		}
    	}else{
    		pmax.pop();
    		while(!pmax.empty()){
    			maxneg *= pmax.top();
    			pmax.pop();
    			flag3 = 1;
    		}
    	}
    	if(flag1){
    		if(flag3){
    			max = maxpos*maxneg;
    		}else{
    			max = maxpos;
    		}
    	}else{
    		if(flag3){
    			max = maxneg;
    		}else{
    			max = 0;
    		}
    	}

    	while(!pmin.empty() && pmin.top()>0){
    		minpos *= pmin.top();
    		pmin.pop();
    		flag4 = 1;
    	}
    	while(!pmin.empty() && pmin.top()==0){
    		pmin.pop();
    		flag5 = 1;
    	}
    	if(pmin.size()%2!=0){
    		while(!pmin.empty()){
    			minneg *= pmin.top();
    			pmin.pop();
    			flag6 = 1;
    		}
    	}else{
    		pmax.pop();
    		while(!pmin.empty()){
    			minneg *= pmin.top();
    			pmin.pop();
    			flag6 = 1;
    		}
    	}
    	if(flag6){
    		if(flag4){
    			min = minneg*minpos;
    		}else{
    			min = minneg;
    		}
    	}else{
    		min = 0;
    	}
    	cout<<max<<" "<<min;
    	cout<<endl;
    }
}