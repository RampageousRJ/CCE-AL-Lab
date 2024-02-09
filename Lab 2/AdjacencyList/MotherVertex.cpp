#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool mother(vector<list<int> > &graph,int v,int start){
    list<int> que;
    list<int>::iterator it;
    int visited[v+1]={0},count=0;
    visited[start]=1;
    que.push_back(start);
    while(!que.empty()){
        int w=que.front();
        que.pop_front();
        count++;
        for(it=graph[w].begin();it!=graph[w].end();it++){
            if(!visited[*it]){
                que.push_back(*it);
                visited[*it]=1;
            }
        }
    }
    if(count==v)
        return true;
    else
        return false;
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
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;
    vector<list<int> > graph(v+1);
    cout<<"Enter connections(S:D)\n";
    for(int i=1;i<=e;i++){
        cin>>s>>d;
        graph[s].push_back(d);
    }
    display(graph);
    // bfs(graph,v,1);
    for(int i=1;i<=v;i++){
        if(mother(graph,v,i))
            cout<<endl<<i<<" is a mother vertex";
        else
            cout<<endl<<i<<" is not a mother vertex";
    }
    return 0;
}