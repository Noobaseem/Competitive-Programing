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

/*Input and output*/
#define si(n) scanf("%d",&n);
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

/*
    Here i am assuming that the vertices in the graph are labelled from 0, 1, 2 .. n-1
*/

/*
    Declaring datastructures to create a adjacencyList
    pair pii :     suppose vertex u is connected to vertex v, and we are looking in ajacency list of u then 
                first element in pair is vertex name i.e (0, 1 .. n-1) and second is the weight of the edge connecting u and v
    adjcList :  The global structure to store the graph information

                e.g adjcList[0] = {(v1,w1),(v2,w2)...(vr,wr)} //Note that right hand side is a vector of pairs
                e.g adjcList[1] = {(v3,w3),(v5,w5)...(vk,wk)}
*/

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;

vvii adjcList(5);

/*Declaring useful constants*/
#define unvisited -1
#define visited 1

/*A global array of vertices to store which vertex is visited and which is not*/
typedef vector<int> vi;
vi dfs_status;

/*
    Defining the loop through the ajacency list of the given vertex 'u'
    Let's say it represents each vertex which is neighbour of u, since neightbours
    of u are stored in the corresponding adjacency list of u thus we iterate over it.
*/
#define trAdj(c,it) for(vii::iterator it = c.begin(); it != c.end(); it++)

/*This is the dfs stack which is maintained internally*/
void dfs(int u){
    printf("%d",u); dfs_status[u] = visited;
    /*try all neighbours 'v' of vertex 'u'*/
    trAdj(adjcList[u], v){
        /*Additional checks to prevent the loops*/
        if(dfs_status[v->first] == unvisited){
            dfs(v->first);
        }
    }
}

int main(int argc, char* argv[]){
    /*Enter the number of vertices in the graph*/
    /*int N;
    si(N);*/
    for0(i,5){
        dfs_status.pb(unvisited);
    }

    adjcList.resize(5);

    /*Sample initialization*/
    adjcList[0].pb(make_pair(1,0));
    adjcList[0].pb(make_pair(2,0));
    adjcList[1].pb(make_pair(0,0));
    adjcList[2].pb(make_pair(0,0));
    adjcList[2].pb(make_pair(3,0));
    adjcList[3].pb(make_pair(4,0));
    adjcList[3].pb(make_pair(2,0));
    adjcList[4].pb(make_pair(3,0));

    /*The loop is necessary to make sure that all disjoint components are being traversed*/
    for0(i,5){
        if(dfs_status[i] == unvisited){
            dfs(i);
        }
    }
}