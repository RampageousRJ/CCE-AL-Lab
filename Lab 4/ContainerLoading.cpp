#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class container{
public:
    int weight;
    int id;
    container(int i){
        id=i;
    }
    container(){}
};

void bubbleSort(container c[],int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            if(c[j].weight>c[j+1].weight){
                container temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
        }
    }
}

void containerLoading(container *c,int cp,int nc,int *x){
    bubbleSort(c,nc);
    for(int i=1;i<=nc && c[i].weight<=cp;i++){
        x[c[i].id]=1;
        cp-=c[i].weight;
    }
    cout<<"\n\n[ ";
    for(int i=1;i<=nc;i++){
        cout<<x[i]<<"  ";
    }
    cout<<" ]";
}

int main(){
    int n,w,cap;
    cout<<"Enter capacity: ";
    cin>>cap;
    cout<<"Enter number of containers: ";
    cin>>n;
    int x[n+1];
    container c[n+1];
    for(int i=1;i<=n;i++){
        cout<<"Enter weight: ";
        cin>>w;
        c[i].id=i;
        c[i].weight=w;
        x[i]=0;
    }
    //bubbleSort(c,n);
    containerLoading(c,cap,n,x);
}
