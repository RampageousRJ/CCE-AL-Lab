#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Knapsack{
    public:
    int c,cw,cp,w[100],p[100],n,bestp;

    Knapsack(int cap,int num){
        bestp=0;
        c=cap;
        cw=cp=0;
        n=num;
        cout<<"Enter profit and weight: ";
        for(int i=0;i<n;i++){
            cin>>p[i]>>w[i];
        }
    }

    float Bound(int i){
        int cleft=c-cw;
        float b=cp;
        while(i<=n && w[i]<=cleft){
            cleft-=w[i];
            b+=p[i++];
        }
        if(i<=n){
            b+=(p[i]/w[i])*cleft;
            return b;
        }
        return b;
    }

    void knapsack(int i){
        if(i>n){
            bestp=cp;
            return;
        }
        if(cw+w[i]<=c){
            cw+=w[i];
            cp+=p[i];
            knapsack(i+1);
            cw-=w[i];
            cp-=p[i];
        }
        if(Bound(i+1)>bestp){
            knapsack(i+1);
        }
    }
};

int main(){
    int cap,n;
    cout<<"Enter capacity and number of containers: ";
    cin>>cap>>n;
    Knapsack k(cap,n);
    k.knapsack(0);
    cout<<"Best Profit: "<<k.bestp;
    return 0;
}
