#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cycle(vector<list<int> > &graph,int start,int parent,int visited[]){
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
            return cycle(graph,*it,start,visited);
        }
    }
    return false;
}

int indegree(vector<list<int> > &graph,int start){
    list<int>::iterator it;
    int count=0;
    for(unsigned int i=1;i<graph.size();i++){
        for(it=graph[i].begin();it!=graph[i].end();it++){
            if(*it==start){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int v,e,s,d;
    cout<<"Enter vertices and edges: ";
    cin>>v>>e;
    vector<list<int> > graph(v+1);
    cout<<"Enter connections: ";
    for(int i=1;i<=e;i++){
        cin>>s>>d;
        graph[s].push_back(d);
    }
    // int visited[v+1]={0};

    for(int i=1;i<=v;i++){
        int in=indegree(graph,i);
        cout<<"\nIndegree of "<<i<<" is "<<in;
    }
    return 0;
}