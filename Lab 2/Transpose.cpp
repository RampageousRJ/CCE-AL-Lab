#include <iostream>
using namespace std;

class int2d{
    public:
    int mat[100][100];
};

int2d transpose(int graph[][100],int n){
    int2d T;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            T.mat[j][i]=graph[i][j];
        }
    }
    return T;
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
    cout<<"\n\nADJACENCY MATRIX: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    int2d T=transpose(graph,v);
    cout<<"\nTRANSPOSE: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<T.mat[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}