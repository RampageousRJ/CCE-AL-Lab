#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort
void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main() {
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n+1]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}