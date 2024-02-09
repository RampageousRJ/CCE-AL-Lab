#include <iostream>
using namespace std;
int count;

int main(){
    int e,v;
    char res='y';
    cout<<"Enter number of edges: ";
    cin>>e;
    cout<<"Enter number of vertices: ";
    cin>>v;
    int graph[v][v];
    int Tgraph[v][v];
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
    cout<<"\nADJECENCY MATRIX: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            Tgraph[i][j]=graph[j][i];
        }
    }
    cout<<"\nTRANSPOSE ADJECENCY MATRIX: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<Tgraph[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}
