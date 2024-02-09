#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cycle(vector<list<int> > &graph,int start,int parent,int *visited){
    list<int>::iterator it;
    visited[start]=1;
    for(it=graph[start].begin();it!=graph[start].end();it++){
        if(*it==parent){
            continue;
        }
        else if(visited[*it]){
            return true;
        }
        else if(!visited[*it]){
            visited[*it]=1;
            return cycle(graph,*it,start,visited);
        }
    }
    return false;
}

int main(){
    int v,e,s,d;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;
    vector<list<int> > graph(v+1);
    cout<<"Enter connections(S:D)\n";
    for(int i=1;i<=e;i++){
        cin>>s>>d;
        graph[s].push_back(d);
        // graph[d].push_back(s);
    }
    int visited[v+1]={0};
    if(cycle(graph,1,-1,visited)){
        cout<<"Cyclic graph";
    }
    else{
        cout<<"Acyclic graph";
    }
    return 0;
}