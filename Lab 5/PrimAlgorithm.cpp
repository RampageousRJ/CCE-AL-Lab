#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 5

bool createsMST(int u, int v, vector<bool> inMST){
   if (u == v)
      return false;
   if (inMST[u] == false && inMST[v] == false)
      return false;
   else if (inMST[u] == true && inMST[v] == true)
      return false;
   return true;
}

void printMinSpanningTree(int graph[][MAX]){
   vector<bool> inMST(MAX, false);
   inMST[0] = true;
   int e = 0, MSTcost = 0;
   while (e < MAX - 1) {
      int min = 99999, a = -1, b = -1;
      for (int i = 0; i < MAX; i++) {
         for (int j = 0; j < MAX; j++) {
            if (graph[i][j] < min) {
               if (createsMST(i, j, inMST)) {
                  min = graph[i][j];
                  a = i;
                  b = j;
               }
            }
         }
      }
      if (a != -1 && b != -1) {
         cout<<"Edge "<<e+1<<" : ("<< a+1 <<" , "<< b+1 <<" ) : cost = "<< min <<endl;
         e++;
         MSTcost += min;
         inMST[b] = inMST[a] = true;
      }
   }
   cout<<"Cost of Minimum spanning tree = "<<MSTcost;
}

int main() {
    int e,w;
    cout<<"Enter number of edges: ";
    cin>>e;
    int graph[MAX][MAX];
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            graph[i][j]=99999;
        }
    }
    int s,d;
    cout<<"Enter edge connections(S:D) and weights\n";
    for(int i=1;i<=e;i++){
        cin>>s>>d>>w;
        graph[s-1][d-1]=w;
    }
    printMinSpanningTree(graph);
    return 0;
    //SAMPLE TEST CASE I  : 14 1 2 12 1 4 25 2 1 12 2 3 11 2 4 8 2 5 12 3 2 11 3 5 17 4 1 25 4 2 8 4 5 15 5 2 12 5 3 17 5 4 15
    //SAMPLE TEST CASE II : 12 1 3 3 2 3 10 2 4 4 3 1 3 3 2 10 3 4 2 3 5 6 4 2 4 4 3 2 4 5 1 5 3 6 5 4 1
     
}