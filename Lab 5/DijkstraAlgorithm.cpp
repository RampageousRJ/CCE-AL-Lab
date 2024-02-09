#include <iostream>
using namespace std;
// #define v 5
void dijkstra(int graph[100][100],int n,int start) {
    int cost[n][n],distance[n],prev[n];
    int visited[n],count,min_dist,next,i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(graph[i][j]==0)
                cost[i][j]=99999;
            else
                cost[i][j]=graph[i][j];
        }
    }
    for(i=0;i<n;i++) {
        distance[i]=cost[start][i];
        prev[i]=start;
        visited[i]=0;
    }
    distance[start]=0;
    visited[start]=1;
    count=1;
    while(count<n-1){
        min_dist=99999;
        for(i=0;i<n;i++){
            if(distance[i]<min_dist && !visited[i]) {
                min_dist=distance[i];
                next=i;
            }
        }
        visited[next]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(min_dist+cost[next][i]<distance[i]) {
                    distance[i]=min_dist+cost[next][i];
                    prev[i]=next;
                }
        count++;
    }
    for(i=0;i<n;i++){
        if(i!=start) {
            cout<<"\nDistance of Node"<<i+1<<" from source : "<<distance[i];
            cout<<"\nPath: "<<i+1;
            j=i;
            do {
                j=prev[j];
                cout<<" <- "<<j+1;
            }while(j!=start);
            cout<<endl;
        }
    }
}
int main() {
   int v,e,w;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;

    int graph[100][100];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=99999;
        }
    }
    int s,d;
    cout<<"Enter edge connections(S:D) and weights\n";
    for(int i=1;i<=e;i++){
        cin>>s>>d>>w;
        graph[s-1][d-1]=w;
    }
    //SAMPLE TEST CASE I: 5 14 1 2 1 1 4 3 1 5 10 2 1 1 2 3 5 3 2 5 3 4 2 3 5 1 4 1 3 4 3 2 4 5 6 5 1 10 5 3 1 5 4 6
    //SAMPLE TEST CASE II: 5 7 1 2 10 2 3 50 4 3 20 4 5 60 1 5 100 3 5 10 1 4 30
   dijkstra(graph,v,0);
   return 0;
}