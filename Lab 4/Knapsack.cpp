#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class item{
public:
    int id,weight,profit;
    double density;
    item(){}
};

void largestOfThree(int a,int b,int c){
    if(a==b && b==c){
        cout<<"\nAny constraint gives optimal solution\nProfit: "<<a;
    }
    else if(a==b){
        cout<<"\nProfit and Weight will give optimum solution\nProfit: "<<a;
    }
    else if(b==c){
        cout<<"\nProfit and Profit-Density will give optimum solution\nProfit: "<<b;
    }
    else if(a==c){
        cout<<"\nWeight and Profit-Density will give optimum solution\nProfit: "<<a;
    }
    else if(a>b && a>c){
        cout<<"\nWeight will give optimum solution\nProfit: "<<a;
    }
    else if(b>a && b>c){
        cout<<"\nProfit will give optimum solution\nProfit: "<<b;
    }
    else{
        cout<<"\nProfit-Density will give optimum solution\nProfit: "<<c;
    }
}

int knapsack_weight(item it[],int ni,int cap,int *x){
    int sumx=0,k=1;
    for(int i=1;i<=ni;i++){
        for(int j=1;j<=ni-i;j++){
            if(it[j].weight>it[j+1].weight){
                item temp=it[j];
                it[j]=it[j+1];
                it[j+1]=temp;
            }
        }
    }
    for(int i=1;i<=ni && it[i].weight<=cap;i++){
        x[it[i].id]=1;
        cap-=it[i].weight;
    }

    for(int i=1;i<=ni;i++){
        if(x[i]==1){
            sumx+=it[k++].profit;
        }
    }
    return sumx;
}

int knapsack_profit(item it[],int ni,int cap,int *y){
    int sumy=0,k=1;
    for(int i=1;i<=ni;i++){
        for(int j=1;j<=ni-i;j++){
            if(it[j].profit<it[j+1].profit){
                item temp=it[j];
                it[j]=it[j+1];
                it[j+1]=temp;
            }
        }
    }
    for(int i=1;i<=ni && it[i].weight<=cap;i++){
        y[it[i].id]=1;
        cap-=it[i].weight;
    }
    for(int i=1;i<=ni;i++){
        if(y[i]==1){
            sumy+=it[k++].profit;
        }
    }
    return sumy;
}

int knapsack_density(item it[],int ni,int cap,int *z){
    int sumz=0,k=1;
    for(int i=1;i<=ni;i++){
        for(int j=1;j<=ni-i;j++){
            if(it[j].density<it[j+1].density){
                item temp=it[j];
                it[j]=it[j+1];
                it[j+1]=temp;
            }
        }
    }
    for(int i=1;i<=ni && it[i].weight<=cap;i++){
        z[it[i].id]=1;
        cap-=it[i].weight;
    }
    for(int i=1;i<=ni;i++){
        if(z[i]==1){
            sumz+=it[k++].profit;
        }
    }
    return sumz;
}

int main(){
    int ni,cap,w,p,sumx,sumy,sumz;
    cout<<"Enter number of items: ";
    cin>>ni;
    cout<<"Enter weight capacity: ";
    cin>>cap;
    item it[ni+1];
    int x[ni+1],y[ni+1],z[ni+1];
    for(int i=1;i<=ni;i++){
        it[i].id=i;
        cout<<"\nEnter weight and profit: ";
        cin>>w>>p;
        it[i].weight=w;
        it[i].profit=p;
        it[i].density=p/w;
        x[i]=y[i]=z[i]=0;
    }
    //3 105 100 20 10 15 10 15
    sumx=knapsack_weight(it,ni,cap,x);
    sumy=knapsack_profit(it,ni,cap,y);
    sumz=knapsack_density(it,ni,cap,z);
    cout<<"\n\n";
    largestOfThree(sumx,sumy,sumz);
    cout<<"\n\n";
    return 0;
}