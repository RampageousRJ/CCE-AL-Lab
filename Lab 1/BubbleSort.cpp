#include <iostream>
using namespace std;

int count=0;
void bubbleSort(int arr[],int n){
    int temp;
    count++;
    for(int i=0;i<n-1;i++){
        count++;
        for(int j=0;j<n-i-1;j++){
            count++;
            count++;
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count+=3;
            }
        }
        count++;
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
        cin>>arr[j];
    }
    bubbleSort(arr,n);
    cout<<"\n\nStep count: "<<count;
}
