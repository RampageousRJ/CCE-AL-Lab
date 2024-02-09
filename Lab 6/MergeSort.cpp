#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<int> L(n1);
    vector<int> R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n+1]={0};
    cout<<"\nEnter array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout<<"\nSorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}