#include<iostream>
using namespace std;
#define MAX 20
struct Node{
    int vertex;
    Node*next;
};

class Graph{
public:
    int n;
    int adjMatrix[MAX][MAX];
    Node*adjList[MAX];
    bool directed;
    Graph(int vertices,bool isDirected){
        n=vertices;
        directed=isDirected;
        for(int i=0;i<n;i++){
            adjList[i]=NULL;
            for(int j=0;j<n;j++)
            adjMatrix[i][j]=0;
        }
    }
    void addEdge(int u,int v){
        adjMatrix[u][v]=1;
        Node*newNode=new Node();
        newNode->vertex=v;
        newNode->next=adjList[u];
        adjList[u]=newNode;
        if(!directed){
            adjMatrix[v][u]=1;
            Node*newNode2=new Node();
            newNode2->vertex=u;
            newNode2->next=adjList[v];
            adjList[v]=newNode2;
        }
    }
    void printMatrix(){
        cout<<"\nAdjacency Matrix:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            cout<<adjMatrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    void printList(){
        cout<<"\nAdjacency List:\n";
        for(int i=0;i<n;i++){
            cout<<i<<"->";
            Node*t=adjList[i];
            while(t!=NULL){
                cout<<t->vertex<<" ";
                t=t->next;
            }
            cout<<"\n";
        }
    }
    int degree(int v){
        int deg=0;
        for(int i=0;i<n;i++)
        if(adjMatrix[v][i]==1)
        deg++;
        return deg;
    }
    int inDegree(int v){
        int indeg=0;
        for(int i=0;i<n;i++)
        if(adjMatrix[i][v]==1)
        indeg++;
        return indeg;
    }
    int outDegree(int v){
        int outdeg=0;
        for(int i=0;i<n;i++)
        if(adjMatrix[v][i]==1)
        outdeg++;
        return outdeg;
    }
    void printAdjacent(int v){
        cout<<"Adjacent to "<<v<<": ";
        Node*t=adjList[v];
        while(t!=NULL){
            cout<<t->vertex<<" ";
            t=t->next;
        }
        cout<<"\n";
    }
    int countEdges(){
        int edges=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(adjMatrix[i][j]==1)
                edges++;
        if(!directed)
        edges/=2;
        return edges;
    }
};
int main(){
    int n,choice,u,v;
    bool directed;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Directed graph? (1=Yes 0=No): ";
    cin>>directed;
    Graph g(n,directed);
    while(1){
        cout<<"\n---MENU---\n";
        cout<<"1.Add Edge\n";
        cout<<"2.Display Adjacency Matrix\n";
        cout<<"3.Display Adjacency List\n";
        cout<<"4.Degree of Vertex\n";
        cout<<"5.In/Out Degree of Vertex\n";
        cout<<"6.Adjacent Vertices\n";
        cout<<"7.Number of Edges\n";
        cout<<"8.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter u v: ";
                cin>>u>>v;
                g.addEdge(u,v);
                break;
            case 2:
                g.printMatrix();
                break;
            case 3:
                g.printList();
                break;
            case 4:
                cout<<"Enter vertex: ";
                cin>>u;
                cout<<"Degree="<<g.degree(u)<<"\n";
                break;
            case 5:
                cout<<"Enter vertex: ";
                cin>>u;
                cout<<"In-degree="<<g.inDegree(u)<<"\n";
                cout<<"Out-degree="<<g.outDegree(u)<<"\n";
                break;
            case 6:
                cout<<"Enter vertex: ";
                cin>>u;
                g.printAdjacent(u);
                break;
            case 7:
                cout<<"Edges="<<g.countEdges()<<"\n";
                break;
            case 8:
                return 0;
            default:
                cout<<"Invalid\n";
        }
    }
}
