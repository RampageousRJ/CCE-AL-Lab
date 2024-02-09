#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void floydmarshal(int graph[100][100], int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<endl;
        for(int j=0;j<v;j++){
            if(i==j){
                cout<<i+1<<" -> "<<j+1<<" : 0"<<endl;
                continue;
            }
            cout<<i+1<<" -> "<<j+1<<" : "<<graph[i][j]<<endl;
        }
    }
}

int main(){
    int v,e,s,d,w;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;
    int graph[100][100];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=999;
        }
    }
    cout<<"\nEnter connections(S:D:W)\n";
    for(int i=1;i<=e;i++){
        cin>>s>>d>>w;
        graph[s-1][d-1]=w;
        // graph[d-1][s-1]=w;
    }
    floydmarshal(graph,v);
    return 0;
}

// 4 5 2 1 2 1 3 3 3 4 1 4 1 6 3 2 7