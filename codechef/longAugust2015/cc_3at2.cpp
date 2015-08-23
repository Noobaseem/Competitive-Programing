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
 
#define MAX 2097152
#define inf 0x7fffffff
 
int arr[1000006];
long long int lazy[MAX];
long long int tree[MAX];

int getMid(int a, int b){
    return a+(b-a)/2;
}
 
void build_tree(int node, int a, int b) {
    if(a > b) return;
 
    if(a == b) {
        tree[node] = arr[a];
        return;
    }
    int mid = getMid(a,b);
    build_tree(node*2, a, mid);
    build_tree(node*2+1, mid+1, b);
    tree[node] = tree[node*2]+tree[node*2+1];
}
 
void update_tree(int node, int a, int b, int i, int j, int value) {
 
    if(lazy[node] != 0) {
        tree[node] += lazy[node]*(b-a+1);
 
        if(a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
 
        lazy[node] = 0;
    }
 
    if(a > b || a > j || b < i)
        return;
 
    if(a >= i && b <= j) {
            tree[node] += value*(b-a+1);
 
        if(a != b) {
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }
 
        return;
    }
    
    int mid = getMid(a,b);

    update_tree(node*2, a, mid, i, j, value);
    update_tree(1+node*2, mid+1, b, i, j, value);
 
    tree[node] = tree[node*2]+tree[node*2+1];
}
 
long long int query_tree(int node, int a, int b, int i, int j) {
 
    if(a > b || a > j || b < i) return 0;
 
    if(lazy[node] != 0) {
        tree[node] += lazy[node]*(b-a+1);
 
        if(a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
 
        lazy[node] = 0;
    }
 
    if(a >= i && b <= j)
        return tree[node];
    
    int mid = getMid(a,b);

    long long int q1 = query_tree(node*2, a, mid, i, j);
    long long int q2 = query_tree(1+node*2, mid+1, b, i, j);
 
    long long int res = q1+q2;
 
    return res;
}
 
int main() {
    int T; si(T);
    while(T--){
        int N, H; si(N); si(H);
        for0(i,N) arr[i] = N;
        memset(lazy, 0, sizeof lazy); memset(tree, 0, sizeof tree);
        build_tree(1, 0, N-1);
        int a, b;
        for0(i,N){
            si(a); si(b);
            update_tree(1, 0, N-1, a, b, -1);
        }
        long long int min = N*H, y;
        int flag = 0;
        for(int i = 0; i < (N-H+1); i++){
            y = query_tree(1, 0, N-1, i, (i+H-1));
            if(y == 0){
                flag = 1;
                break;
            }
            if(min > y) min = y;
        }
        if(flag){
            cout<<0;
        }else{
            cout<<N*H-min<<endl;    
        }
        
    }
}  