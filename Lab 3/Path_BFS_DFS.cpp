#include <iostream>
#include <bits/stdc++.h>
using namespace std;

list<int> bfs_path(vector<list<int> > &graph,int start,int end){
    list<int>::iterator it;
    list<int>::iterator iter;
    list<int> path;
    list<int> emp;
    list<int> que;
    que.push_back(start);
    int visited[graph.size()+1]={0};
    visited[start]=1;
    while(!que.empty()){
        int w=que.front();
        que.pop_front();
        path.push_back(w);
        for(it=graph[w].begin();it!=graph[w].end();it++){
            if(*it==end){
                path.push_back(end);
                return path;
            }
            else if(!visited[*it]){
                visited[*it]=1;
                que.push_back(*it);
            }
        }
    }
    return emp;
}

list<int> dfs_path(vector<list<int> > &graph,int start,int end){
    list<int>::iterator it;
    list<int> stk;
    list<int> path;
    list<int> emp;
    stk.push_back(start);
    int visited[graph.size()+1]={0};
    visited[start]=1;
    while(!stk.empty()){
        int w=stk.back();
        stk.pop_back();
        path.push_back(w);
        for(it=graph[w].begin();it!=graph[w].end();it++){
            if(*it==end){
                path.push_back(end);
                return path;
            }
            else if(!visited[*it]){
                visited[*it]=1;
                stk.push_back(*it);
            }
        }
    }
    return emp;
}

int main(){
    int s,d,v,e;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;
    vector<list<int> > graph(v+1);
    vector<list<int> > path;
    list<int>::iterator iter;
    cout<<"Enter connections(S:D)\n";
    for(int i=1;i<=e;i++){
        cin>>s>>d;
        graph[s].push_back(d);
    }
    path.push_back(bfs_path(graph,1,5));
    path.push_back(dfs_path(graph,1,5));
    for(unsigned int i=0;i<path.size();i++){
        cout<<"\nPATH "<<i+1<<endl;
        for(iter=path[i].begin();iter!=path[i].end();iter++){
            cout<<*iter<<" -> ";
        }
    }
}