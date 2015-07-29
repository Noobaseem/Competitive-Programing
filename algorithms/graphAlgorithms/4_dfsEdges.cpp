/*
*    @author: Aseem Rastogi
*    alumini: National Institute of Technology, Hamirpur
*         Batch of 2014
*    mail_id: aseem.rastogi1992@gmail.com
*/
 
/*
    This is the code to find the number of back-edges, cross-edges/forward-edges, tree-edges in the graph
    This can be done by using DFS algorithm.
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

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;

vvii adjcList(5);

#define DFS_WHITE 1
#define DFS_GRAY 2
#define DFS_BLACK 3

typedef vector<int> vi;
vi dfs_status;
vi dfs_parent;

#define trAdj(c,it) for(vii::iterator it = c.begin(); it != c.end(); it++)

/*This is the dfs stack which is maintained internally*/
void dfsEdges(int u){
    dfs_status[u] = DFS_GRAY;
    trAdj(adjcList[u],v){
        /*From gray vertex to white vertex i.e it is a tree edge*/
        if(dfs_status[v->first] == DFS_WHITE){
            printf("There is a tree edge from %d -> %d\n",u,v->first);
            dfs_parent[v->first] = u;
            dfsEdges(v->first);
        }else if(dfs_status[v->first] == DFS_GRAY){
            if(v->first == dfs_parent[u]){
                printf("Bidirectional edge from %d -> %d\n",u, v->first);
            }else{
                printf("backward edge from %d -> %d",u,v->first);
            }
        }else if(dfs_status[v->first] == DFS_BLACK){
            printf("There is a forward edge from %d -> %d\n",u,v->first);
        }
    }
    /*Finally when the node is fully traversed then mark it as black*/
    dfs_status[u] = DFS_BLACK;
}

int main(int argc, char* argv[]){
    /*Enter the number of vertices in the graph*/
    int N;
    si(N);
    dfs_status.resize(N);
    dfs_parent.resize(N);
    for0(i,N){
        dfs_status[i] = DFS_WHITE;
        dfs_parent[i] = i;
    }
    adjcList.resize(N);

    /*Sample initialization*/
    adjcList[0].pb(make_pair(1,0));
    adjcList[0].pb(make_pair(2,0));
    adjcList[1].pb(make_pair(0,0));
    adjcList[2].pb(make_pair(0,0));
    adjcList[3].pb(make_pair(4,0));
    adjcList[3].pb(make_pair(2,0));
    adjcList[4].pb(make_pair(3,0));

    /*The loop is necessary to make sure that all disjoint components are being traversed*/
    for0(i,N){
        if(dfs_status[i] == DFS_WHITE){
            dfsEdges(i);
        }
    }
}