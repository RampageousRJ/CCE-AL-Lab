#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool connected(vector<list<int> > &graph,int v,int start){
    list<int>::iterator it;
    list<int> Q;
    int visited[v+1]={0},count=0;
    visited[start]=1;
    Q.push_back(start);
    while(!Q.empty()){
        int w=Q.front();
        Q.pop_front();
        // cout<<w<<"  ";
        count++;
        for(it=graph[w].begin();it!=graph[w].end();it++){
            if(!visited[*it]){
                Q.push_back(*it);
                visited[*it]=1;
            }
        }
    }
    if(count==v)
        return true;
    else
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
    if(connected(graph,v,1)){
        cout<<"Connected graph\n\n";
    }
    else{
        cout<<"Disconnected graph\n\n";
    }
}