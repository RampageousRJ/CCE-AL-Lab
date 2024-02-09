#include <iostream>
using namespace std;

int count=0;
void selectionSort(int arr[],int n){
    int pos;
    count++;
    for(int i=0;i<n-1;i++){
        count++;
        pos=i;
        count++;
        for(int j=i+1;j<n;j++){
            count++;
            count++;
            if(arr[j]<arr[pos]){
                pos=j;
                count++;
            }
        }
        count++;
        int temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
        count+=3;
    }
    count++;
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
    selectionSort(arr,n);
    cout<<"\nARRAY AFTER SORT:\n";
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    cout<<"\n\nStep count: "<<count;
}

