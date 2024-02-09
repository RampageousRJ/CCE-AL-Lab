#include <iostream>
#include <queue>
using namespace std;

void BFS(int start,int graph[][100],int n){
    int visited[n+1];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    queue<int> Q;
    visited[start]=1;
    Q.push(start);
    cout<<"BFS Sequence: "<<start+1<<"  ";
    while(!Q.empty()){
        int w=Q.front();
        Q.pop();
        for(int u=0;u<n;u++){
            if(graph[w][u]!=0 && visited[u]==0){
                Q.push(u);
                visited[u]=1;
                cout<<u+1<<"  ";
            }
        }
    }
}

int main(){
    int e,v;
    cout<<"Enter number of edges and vertices: ";
    cin>>e>>v;
    int graph[100][100];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }
    int s,d;
    cout<<"Enter edge connections S:D\n";
    for(int i=1;i<=e;i++){
        cin>>s>>d;
        graph[s-1][d-1]=1;
    }
    //5 5 3 2 2 1 1 3 1 4 4 5
    cout<<"\nADJACENCY MATRIX: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    BFS(0,graph,v);
    return 0;
}