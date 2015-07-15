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
    		long long int count = 0;
    		long long int carry = 0;
    		long int prev = 0;
    		long long int r = 0;
    		long long int N, K;
    		cin>>N>>K;
    		long long int A[N];
    		for0(i,N){
    			cin>>A[i];
    			prev = (carry ? 1 : 0);
    			if(carry == 1){
    				count++;
    			}
    			if(A[i]+prev>=carry){
    				count += (A[i] + prev -carry)/K;
    				r = (A[i]+prev-carry)%K;
    				if(prev == 1 && carry != 1) count++;
    				if(r==0){
    					carry = 0;
    				}else{
    					carry = K - r;
    				}
    			}else{
    				carry = carry-(A[i]+prev);
    			}
    			if(i == N-1 && carry > 0){
    				count++;
    			}
    			
    			
    		}
    		cout<<count<<endl;
     
    	}	
    } 