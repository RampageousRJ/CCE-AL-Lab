#include <iostream>
using namespace std;

int count=0;
int linearSearch(int arr[],int n,int ele){
    int i;
    count++;
    for(i=0;i<n && arr[i]!=ele;i++){
        count++;
    }
    count++;
    if(i==n){
            count++;
            count++;
            return -1;
    }
    else{
        count++;
        count++;
        return i;
    }
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
    cout<<"Enter element to be searched: ";
    cin>>ele;
    int ind=linearSearch(arr,n,ele);
    if(ind>-1){
        cout<<"Element found at "<<ind;
    }
    else{
        cout<<"Element not found";
    }
    cout<<"\n\nStep count: "<<count;
}
