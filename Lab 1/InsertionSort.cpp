
#include <iostream>
using namespace std;

int count=0;
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        // count++;
        int pos=arr[i],j=i-1;
        // count++;
        for(;j>=0 && arr[j]>pos;j--){
            // count++;
            arr[j+1]=arr[j];
            // count++;
        }
        // count++;
        arr[j+1]=pos;
        // count++;
    }
    // count++;
}

int main(){
    int n,ele;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Input array: \n";
    for(int j=0;j<n;j++){
        arr[j]=n-j;
    }
    insertionSort(arr,n);
    cout<<"\nARRAY AFTER SORT:\n";
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    cout<<"\n\nStep count: "<<count;
}
