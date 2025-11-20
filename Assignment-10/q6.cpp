#include <iostream>
using namespace std;

int main(){
    int n=5;
    int adj[5][5]={ {0,2,3,0,0}, {2,0,1,4,0}, {3,1,0,0,5}, {0,4,0,0,0}, {0,0,5,0,0}};
    int dist[5],vis[5]={0};
    for(int i=0;i<n;i++) 
    dist[i]=99999;
    int start=0;
    dist[start]=0;
    for(int i=0;i<n;i++){
        int u=-1;
        for(int j=0;j<n;j++){
            if(!vis[j] && (u==-1 || dist[j]<dist[u])) u=j;
        }
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(adj[u][v] && !vis[v] && dist[u]+adj[u][v]<dist[v]){
                dist[v]=dist[u]+adj[u][v];
            }
        }
    }
    cout<<"Dijkstra distances from 0:\n";
    for(int i=0;i<n;i++){
        cout<<"0 -> "<<i<<" = "<<dist[i]<<"\n";
    }
}
