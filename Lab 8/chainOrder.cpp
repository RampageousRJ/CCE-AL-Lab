#include <iostream>
using namespace std;
int matrixOrderChain(int chain[], int i, int j){
    int cnt, minNum = INT_MAX;
    if(i == j){
        return 0;
    }
    for(int k = i; k < j; k++){
        cnt = matrixOrderChain(chain,i,k) + matrixOrderChain(chain, k+1, j) + chain[i-1]*chain[k]*chain[j];
        minNum = min(cnt,minNum);
    }
    return minNum;
}
int main(){
    int arr[100], n;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter Elements : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << matrixOrderChain(arr, 1, n-1);

    return 0;
}