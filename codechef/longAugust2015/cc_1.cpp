    /*
    *    @author: Aseem Rastogi
    *    alumini: National Institute of Technology, Hamirpur
    *         Batch of 2014
    *    mail_id: aseem.rastogi1992@gmail.com
    */
     
    #include <bits/stdc++.h>
     
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
    #define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )
    #define siz 1000
     
    /*Read and write user inputs*/
    #define si(n) scanf("%d",&n)
     
    bool isPowerOfTwo(int x){
        return x && (!(x&(x-1)));
    }
     
    int main(int argc, char* argv[]){
        int T; si(T);
        while(T--){
            int o = 0;
            int A,B; si(A); si(B);
            int flag = 0;
            if(!isPowerOfTwo(A)){
                while(!isPowerOfTwo(A)){
                    flag = 1;
                    if(A%2==0){
                        A = A/2;
                        o++;
                    }else{
                        A = (A-1)/2;
                        o++;
                    }
                }
            }
            if(A > B){
                while(A != B){
                    o++;
                    A /= 2;
                }
            }else if(A == B){
                if(!flag) o = 0;
            }else{
                while(A != B){
                    o++;
                    A *= 2;
                }
            }
            cout<<o<<endl;
        }
    } 