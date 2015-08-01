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

typedef priority_queue<int> pi;
typedef map<int, int> mi;

int main(int argc, char* argv[]){
    int Q;
    si(Q);
    pi qp, qn;
    mi mp;
    int q,temp;
    for0(i,Q){
    	cin>>q;
    	if(q == 1){
    		cin>>temp;
			if(mp.find(temp) != mp.end()){
				mp[temp]++;
			}else{
				mp[temp] = 1;
			}
			qp.push(temp);
			qn.push(-1*temp);
		}
		else if(q == 2) {
			cin>>temp;
			if(mp[temp] > 0){
				mp[temp]--;
			}else{
				cout<<-1<<endl;	
			}			
		}
    	else if(q == 3) {
			while(mp[qp.top()] == 0 && qp.size() > 0){
				qp.pop();
			}
			if(qp.size() > 0){
				cout<<qp.top()<<endl;	
			}else{
				cout<<-1<<endl;
			}
		}
		else{
			while(mp[-1*(qn.top())] == 0 && qn.size() > 0){
				qn.pop();
			}
			if(qn.size() > 0){
				cout<<-1*(qn.top())<<endl;
			}else{
				cout<<-1<<endl;
			}
    	}
    }
}