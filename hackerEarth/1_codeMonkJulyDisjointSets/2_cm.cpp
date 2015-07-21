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

struct ancestor{
    int p;
    int e;
};

int weight[1000];
struct ancestor parent[1000];

int parentComparator(const void* a, const void* b){
    int l = ((struct ancestor *) a)->p;
    int r = ((struct ancestor *) b)->p;
    return l-r;
}

void makeset(int size) {
    int abCost = 0;
    for0(i,size){
        cin>>abCost;
        parent[i].p = i;
        parent[i].e = abCost;
        weight[i] = 1;
    }
}

/*Quick find with path compression*/
int qFind(int item){
    int newItem = item;
    int root    = item;
    /*Check if we have reached the root*/
    while(root != parent[root].p){
        root = parent[root].p;
    }
    /*Apply path compression so that all child nodes point to the parent node*/
    while(item != root){
        newItem      = parent[item].p;
        parent[item].p = root;
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
        parent[l].p = r;
        weight[r] += weight[l];
    }else{
        parent[r].p = l;
        weight[l] += weight[r];
    }
    count--;
}
 
int main(int argc, char* argv[]){
    /*Initially take the number of the disjoint sets that are originally present i.e the size of the input array*/
    int count;
    int temp;
    si(count);
    temp = count;
    makeset(count);
    int K;
    cin>>K;
    int x, y;
    for0(i,K){
        cin>>x>>y;
        qUnion(x-1,y-1,count);
    }
    qsort(parent, temp, sizeof(parent[0]), parentComparator);
    int cost = 1;
    int count1 = 1;
    int value = -1;
    int min = 1005;
    for0(i,temp){
        if(value != parent[i].p){
            cost = (cost*count1)%MOD;
            min = parent[i].e;
            value = parent[i].p;
            count1 = 1;
        }else{
            if(parent[i].e == min){
                count1++;
            }else if(parent[i].e < min){
                count1 = 1;
                min = parent[i].e;
            }
        }
    }
    cout<<cost;
}