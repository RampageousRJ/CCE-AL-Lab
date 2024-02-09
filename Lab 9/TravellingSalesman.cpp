#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n;
int D[10][10];
int completed_visit;
int cost[16][4];
int TSP(int mark,int pos){
  if(mark==completed_visit){
    return D[pos][0];
  }
  if(cost[mark][pos]!=-1){
     return cost[mark][pos];
  }
  int ans = INT_MAX;
  for(int city=0;city<n;city++){
    if((mark&(1<<city))==0){
      int newans = D[pos][city] + TSP( mark|(1<<city),city);
      ans = min(ans, newans);
    }
  }
  return cost[mark][pos] = ans;
}

int main(){
    cout << "Enter the number of places you want to visit: ";
    cin >> n;

    completed_visit = (1<<n) -1;

    cout << "Enter the distance matrix:\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> D[i][j];
        }
    }

    memset(cost, -1, sizeof(cost));

    cout<<"Minimum distance Travelled by you is "<<TSP(1,0);

    return 0;
}
