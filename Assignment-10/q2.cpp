#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n = 5;
    int adj[5][5] = {{0,1,1,0,0}, {1,0,0,1,0},{1,0,0,0,1},{0,1,0,0,0}, {0,0,1,0,0} };
    int vis[5]={0};
    queue<int>q;
    int start=0;
    vis[start]=1;
    q.push(start);
    cout<<"BFS: ";
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v=0;v<n;v++){
            if(adj[u][v]==1 && !vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
