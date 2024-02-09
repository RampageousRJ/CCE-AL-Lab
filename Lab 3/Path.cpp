#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void path(vector<list<int> > &graph,int start,int end){
    list<int>::iterator it;
    list<int> stk;
    list<int> path;
    int visited[graph.size()]={0};
    visited[start]=1;
    int flag=0;
    stk.push_back(start);
    while(!stk.empty() && flag==0){
        int w=stk.back();
        stk.pop_back();
        path.push_back(w);
        for(it=graph[w].begin();it!=graph[w].end();it++){
            if(*it==end){
                flag=1;
                path.push_back(*it);
            }
            else if(!visited[*it]){
                visited[*it]=1;
                stk.push_back(*it);
            }
        }
    }
    if(flag){
        for(it=path.begin();it!=path.end();it++){
            cout<<*it<<"  ";
        }
    }
    else{
        cout<<"No Path Exists";
    }
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
    }
    path(graph,1,6);
}
