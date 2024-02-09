#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int indegree(vector<list<int> > &graph,int start){
    list<int>::iterator it;
    int count=0;
    for(int i=1;i<graph.size();i++){
        for(it=graph[i].begin();it!=graph[i].end();it++){
            if(*it==start){
                count++;
            }
        }
    }
    return count;
}

void TopologicalSort(vector<list<int> > &graph){
    vector<int> indeg(graph.size());
    list<int> stk;
    list<int>::iterator it;
    for(unsigned int i=1;i<graph.size();i++){
        indeg[i]=indegree(graph,i);
    }
    int visited[graph.size()]={0};
    cout<<"Topologically Sorted Order:  ";
    for(int i=1;i<graph.size();i++){
        if(!indeg[i]){
            stk.push_back(i);
            visited[i]=1;
        }
    }
    while(!stk.empty()){
        int val=stk.back();
        stk.pop_back();
        cout<<val<<"  ";
        for(it=graph[val].begin();it!=graph[val].end();it++){
            indeg[*it]--;
        }
        for(int i=1;i<graph.size();i++){
            if(!indeg[i] && !visited[i]){
                visited[i]=1;
                stk.push_back(i);
            }
        }
    }
}

int main(){
    // 6 7 1 3 1 4 2 4 2 5 3 6 4 6 5 6
    int v,e,s,d;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;
    cout<<"Enter connections(S:D)\n";
    vector<list<int> > graph(v+1);
    vector<int> topologicalSort(v+1);
    for(int i=1;i<=e;i++){
        cin>>s>>d;
        graph[s].push_back(d);
    }
    TopologicalSort(graph);
    return 0;
}