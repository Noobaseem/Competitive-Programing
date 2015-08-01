#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> p;
typedef vector<p> vii;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, M;
        cin>>N>>M;
        vi vertices(N);
        vii edges;
        int a,b;
        pair <int,int> foo;
        for(int i = 0; i < N; i++){
            vertices[i] = 0;
        }
        for(int i = 0; i < M; i++){
            cin>>a>>b;
            foo = make_pair (a-1,b-1);
            edges.push_back(foo);
        }
        int x;
        int u,v;
        for(int i = 0; i < N-1; i++){
            cin>>x;
            x--;
            u = edges[x].first;
            v = edges[x].second;
            vertices[u] += 1;
            vertices[v] += 1;
        }
        int count = 0;
        for(int i = 0; i < N; i++){
            if(vertices[i] == 0){
                count = 1;
                break;
            }
        }
        (count == 1) ? cout<<"NO\n" : cout<<"YES\n";
    }
}