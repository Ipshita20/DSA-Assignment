#include<iostream>
using namespace std;

struct Edge{
    int u,v,w;
};
int parent[100],sz[100];
int find(int x){
    if(parent[x]==x)
    return x;
    return parent[x]=find(parent[x]);
}
bool unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)
    return false;
    if(sz[a]<sz[b])
    swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];
    return true;
}
void bubbleSort(Edge e[],int m){
    for(int i=0;i<m-1;i++){
        for(int j=0;j<m-i-1;j++){
            if(e[j].w>e[j+1].w){
                Edge temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }
}
int main(){
    int n,m;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    Edge e[100];
    cout<<"Enter edges (u v w):\n";
    for(int i=0;i<m;i++)
    cin>>e[i].u>>e[i].v>>e[i].w;
    bubbleSort(e,m);
    for(int i=0;i<n;i++){
        parent[i]=i;
        sz[i]=1;
    }
    int mst=0;
    cout<<"\nKruskal MST edges:\n";
    for(int i=0;i<m;i++){
        if(unite(e[i].u,e[i].v)){
            mst+=e[i].w;
            cout<<e[i].u<<"-"<<e[i].v<<" : "<<e[i].w<<"\n";
        }
    }
    cout<<"Total Weight="<<mst<<"\n";
    return 0;
}
