#include <iostream>
using namespace std;

void AllPairShortest(int graph[100][100],int v,int kay[100][100]){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(i==j){
                    continue;
                }
                int temp = graph[i][k] + graph[k][j];
                if(temp<graph[i][j]){
                    kay[i][j]=k+1;
                    graph[i][j]=temp;
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<"\n\nAllPairShortest for "<<i+1<<": \n";
        for(int j=0;j<v;j++){
            if(i==j){
                cout<<endl<<i+1<<" -> "<<j+1<<" = "<<0;
                continue;
            }
            cout<<endl<<i+1<<" -> "<<j+1<<" = "<<graph[i][j];
        }
    }
    cout<<"\n\nKay Matrix: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<kay[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n\nCost Matrix: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    int v,e,w;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;
    int graph[100][100];
    int kay[100][100]={0};
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=99999;
        }
        graph[i][i]=0;
    }
    int s,d;
    cout<<"Enter edge connections(S:D) and weights\n";
    for(int i=1;i<=e;i++){
        cin>>s>>d>>w;
        graph[s-1][d-1]=w;
    }
    //SAMPLE TEST CASE I: 5 14 1 2 1 1 4 3 1 5 10 2 1 1 2 3 5 3 2 5 3 4 2 3 5 1 4 1 3 4 3 2 4 5 6 5 1 10 5 3 1 5 4 6
    //SAMPLE TEST CASE II: 5 7 1 2 10 2 3 50 4 3 20 4 5 60 1 5 100 3 5 10 1 4 30
    //SAMPLE TEST CASE III: 4 5 2 1 2 1 3 3 3 4 1 4 1 6 3 2 7
   AllPairShortest(graph,v,kay);
   return 0;
}