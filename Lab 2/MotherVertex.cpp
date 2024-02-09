#include <iostream>
#include <stack>
using namespace std;
int counter=0;

void Mother(int start,int graph[][100],int n){
    int visited[n+1];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    stack<int> S;
    visited[start]=1;
    S.push(start);
    counter++;
    while(!S.empty()){
        int w=S.top();
        S.pop();
        for(int u=0;u<n;u++){
            if(graph[w][u]!=0 && visited[u]==0){
                S.push(u);
                visited[u]=1;
                counter++;
            }
        }
    }
}

int main(){
    int e,v;
    cout<<"Enter number of edges: ";
    cin>>e;
    cout<<"Enter number of vertices: ";
    cin>>v;
    int graph[100][100];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }
    int s,d;
    for(int i=1;i<=e;i++){
        cout<<"Enter source: ";
        cin>>s;
        cout<<"Enter destination: ";
        cin>>d;
        graph[s-1][d-1]=1;
    }
    //5 5 3 2 2 1 1 3 1 4 4 5
    cout<<"\nADJACENCY MATRIX: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"\n\n";
    for(int i=0;i<v;i++){
        Mother(i,graph,v);
        if(counter==v)
            cout<<endl<<i<<" is a mother vertex";
        else
            cout<<endl<<i<<" is not a mother vertex";
        counter=0;
    }
    return 0;
}