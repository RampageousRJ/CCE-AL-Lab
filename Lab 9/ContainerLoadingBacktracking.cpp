#include<iostream>
#define MAX 100
using namespace std;

class Loading{
    public:
        int n,c,bestw,cw,r;
        int w[MAX],bestx[MAX];

        void maxloading(int i, int x[]){
            if(i > n){
                for(int j = 1; j <= n ;j++ ){
                    bestx[j] = x[j];
                }
                bestw = cw;
                return;
            }
            r -= w[i];
            if(cw+w[i] <= c){
                x[i] = 1;
                cw += w[i];
                maxloading(i+1,x);
                cw-=w[i];
            }
            if(cw + r > bestw){
                x[i] = 0;
                maxloading(i+1,x);
                r+=w[i];
            }
        }
};

void Maxloading(int w[], int c, int n, int bestx[]){
    Loading X;
    int x[n+1] = {0};
    for(int i = 1; i <= n; i++){
        X.w[i] = w[i];
    }
    X.n = n;
    X.c = c;
    X.bestw = 0;
    for(int i = 1; i <= n; i++){
        X.bestx[i] = bestx[i];
    }
    X.cw = 0;
    X.r = 0;
    for(int i = 1; i <= n; i++){
        X.r += w[i];
    }
    X.maxloading(1,x);

    for(int i = 1; i <= n; i++){
        cout << X.bestx[i] << " ";
    }
    cout <<endl;
}

int main(){
    int cap,n;

    cout << "Enter capacity :";
    cin >> cap;
    cout << "Enter number of containers : ";
    cin >> n;
    int w[n+1],bestx[n+1] = {0};
    for(int i = 1; i <= n; i++){
        cout << "Weight of Container " << i <<" :";
        cin >> w[i];
    }
    Maxloading(w, cap, n, bestx);
    return 0;
}