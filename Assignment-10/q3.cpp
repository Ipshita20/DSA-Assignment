#include <iostream>
using namespace std;

int adj[5][5]={ {0,1,1,0,0},{1,0,0,1,0},{1,0,0,0,1},{0,1,0,0,0},{0,0,1,0,0}};
int vis[5]={0};
int n=5;

void dfs(int u){
    vis[u]=1;
    cout<<u<<" ";
    for(int v=0;v<n;v++){
        if(adj[u][v]==1 && !vis[v]){
            dfs(v);
        }
    }
}
int main(){
    cout<<"DFS: ";
    dfs(0);
}

