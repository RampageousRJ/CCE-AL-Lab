#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<list<int> > &graph,int v,int start){
    list<int> stk;
    list<int>::iterator it;
    int visited[v+1]={0};
    visited[start]=1;
    cout<<"DFS Sequence: ";
    stk.push_back(start);
    while(!stk.empty()){
        int w = stk.back();
        cout<<w<<"  ";
        stk.pop_back();
        for(it=graph[w].begin();it!=graph[w].end();it++){
            if(!visited[*it]){
                visited[*it]=1;
                stk.push_back(*it);
            }
        }
    }
}

void bfs(vector<list<int> > &graph,int v,int start){
    list<int> que;
    list<int>::iterator it;
    int visited[v+1]={0};
    visited[start]=1;
    cout<<"BFS Sequence:  ";
    que.push_back(start);
    while(!que.empty()){
        int w=que.front();
        que.pop_front();
        cout<<w<<"  ";
        for(it=graph[w].begin();it!=graph[w].end();it++){
            if(!visited[*it]){
                que.push_back(*it);
                visited[*it]=1;
            }
        }
    }
}

void dfs_recursive(vector<list<int> > &graph,int visited[],int start){
    list<int> l1=graph[start];
    list<int>::iterator it;
    visited[start]=1;
    cout<<start<<"  ";
    for(it=l1.begin();it!=l1.end();it++){
        if(!visited[*it]){
            dfs_recursive(graph,visited,*it);
        }
    }
}


void display(vector<list<int> > &graph){
    list<int>::iterator it;
    cout<<endl<<endl;
    for(unsigned int i=1;i<graph.size();i++){
        cout<<i<<" -> ";
        for(it=graph[i].begin();it!=graph[i].end();it++){
            cout<<*it<<" -> ";
        }
        cout<<endl<<"|"<<endl;
    }
    cout<<endl<<endl;
}

int main(){
    int v,e,s,d;
    cout<<"Enter number of vertices and edges:  ";
    cin>>v>>e;
    vector<list<int> > graph(v+1);
    cout<<"Enter connections(S:D)\n";
    for(int i=1;i<=e;i++){
        cin>>s>>d;
        graph.at(s).push_back(d);
        graph.at(d).push_back(s);
    }
    //4 4 1 2 2 3 3 4 4 2
    display(graph);
    int visited[v+1]={0};
    // dfs(graph,v,1);
    bfs(graph,v,1);
    // dfs_recursive(graph,visited,1);
    return 0;
}