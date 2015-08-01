/*
*   @author: Aseem Rastogi
*   alumini: National Institute of Technology, Hamirpur
*        Batch of 2014
*   mail_id: aseem.rastogi1992@gmail.com
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

int main(int argc, char* argv[]){
    int T;
    si(T);
    pi Q;
    int temp;
    long long int A[T];
    long long int a;
    long long int b;
    long long int c;
    A[0] = -1;
    A[1] = -1;
    for0(i,T){
        cin>>temp;
        Q.push(temp);
        if(i>=2){
            a = Q.top();
            Q.pop();
            b = Q.top();
            Q.pop();
            c = Q.top();
            Q.pop();
            A[i] = a*b*c;
            Q.push(a);
            Q.push(b);
            Q.push(c);
        }
    }
    for0(i,T){
        cout<<A[i]<<"\n";
    }
}