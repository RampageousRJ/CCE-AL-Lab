#include <iostream>
#include <queue>
using namespace std;

void DFS_Recursive(int graph[][100],int start,int visited[],int n){
    visited[start]=1;
    cout<<start+1<<"  ";
    for(int u=0;u<n;u++){
        if(graph[u][start]!=0 && visited[u]==0){
            DFS_Recursive(graph,u,visited,n);
        }
    }
}

int main(){
    int e,v;
    cout<<"Enter number of edges: ";
    cin>>e;
    cout<<"Enter number of vertices: ";
    cin>>v;
    int graph[100][100];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }
    int visited[v+1];
    for(int i=0;i<v;i++)
        visited[i]=0;
    int s,d;
    for(int i=1;i<=e;i++){
        cout<<"Enter source: ";
        cin>>s;
        cout<<"Enter destination: ";
        cin>>d;
        graph[s-1][d-1]=1;
        graph[d-1][s-1]=1;
    }
    cout<<"\nADJECENCY MATRIX: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"\nDFS Sequence: ";
    DFS_Recursive(graph,0,visited,v);
    cout<<endl;
    return 0;
}
