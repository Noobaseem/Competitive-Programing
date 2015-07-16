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
#define si(n) scanf("%d",&n);

/*Useful datastructures*/
typedef vector<int> vi;

/*Important declarations for the disjoin-union sets*/

vi parent;
vi weight;

void makeset(int size) {
    for0(i,size){
        parent.pb(i);
        weight.pb(1);
    }
}

/*Quick find with path compression*/
int qFind(int item){
    int newItem = item;
    int root    = item;
    /*Check if we have reached the root*/
    while(root != parent[root]){
        root = parent[root];
    }
    /*Apply path compression so that all child nodes point to the parent node*/
    while(item != root){
        newItem      = parent[item];
        parent[item] = root;
        item         = newItem; 
    }
    return root;
}

/*Quick union along with the weight heuristic*/
void qUnion(int item1, int item2, int & count){
    int l, r;
    l = qFind(item1);
    r = qFind(item2);
    /*If l and r belong to the same set then return*/
    if(l == r) return;
    /*Compare the weights of the roots nodes, make smaller root point to bigger root*/
    if(weight[l] < weight[r]){
        parent[l] = r;
        weight[r] += weight[l];
    }else{
        parent[r] = l;
        weight[l] += weight[r];
    }
    count--;
}
 
int main(int argc, char* argv[]){
    /*Initially take the number of the disjoint sets that are originally present i.e the size of the input array*/
    int count;
    si(count);
    makeset(count);
    qUnion(1, 2, count);
    qUnion(2, 3, count);
    cout<<count;
}