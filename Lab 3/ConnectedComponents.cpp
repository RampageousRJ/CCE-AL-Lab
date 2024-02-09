#include<iostream>
#include<bits/stdc++.h>
using namespace std;

list<int> connected_component(vector<list<int> > &graph,int visited[],int start){
    list<int>::iterator it;
    list<int> path;
    list<int> stk;
    visited[start]=1;
    path.push_back(start);
    stk.push_back(start);
    while(!stk.empty()){
        int w=stk.back();
        stk.pop_back();
        for(it=graph[w].begin();it!=graph[w].end();it++){
            if(!visited[*it]){
                stk.push_back(*it);
                visited[*it]=1;
                path.push_back(*it);
            }
        }
    }
    return path;
}



int main(){
    int v,e,s,d;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;
    vector<list<int> > graph(v+1);
    vector<list<int> > connections;
    cout<<"Enter connection(S:D)\n";
    for(int i=1;i<=e;i++){
        cin>>s>>d;
        graph[s].push_back(d);
    }
    int visited[v+1]={0};
    for(int i=1;i<=v;i++){
        if(!visited[i]){
            connections.push_back(connected_component(graph,visited,i));
            i=0;
        }
    }
    //5 5 3 2 2 1 1 3 1 4 4 5
    list<int>::iterator it;
    cout<<endl<<endl;
    cout<<"Number of components: "<<connections.size()<<endl<<endl;
    for(unsigned int i=0;i<connections.size();i++){
        cout<<"COMPONENT "<<i+1<<": \n";
        for(it=connections[i].begin();it!=connections[i].end();it++){
            cout<<*it<<" -> ";
        }
        cout<<endl<<endl;
    }
    return 0;
}