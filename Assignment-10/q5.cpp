#include <iostream>
using namespace std;

int main(){
    int n=5;
    int adj[5][5]={{0,2,3,0,0},{2,0,1,4,0},{3,1,0,0,5},{0,4,0,0,0},{0,0,5,0,0}};
    int key[5],parent[5],mstSet[5]={0};
    for(int i=0;i<n;i++){
        key[i]=99999;
        parent[i]=-1;
    }
    key[0]=0;
    for(int i=0;i<n;i++){
        int u=-1;
        for(int j=0;j<n;j++){
            if(!mstSet[j] && (u==-1||key[j]<key[u])) u=j;
        }
        mstSet[u]=1;
        for(int v=0;v<n;v++){
            if(adj[u][v] && !mstSet[v] && adj[u][v]<key[v]){
                key[v]=adj[u][v];
                parent[v]=u;
            }
        }
    }
    cout<<"Prim MST:\n";
    int total=0;
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<" : "<<adj[parent[i]][i]<<"\n";
        total+=adj[parent[i]][i];
    }
    cout<<"Total Weight = "<<total<<"\n";
}
