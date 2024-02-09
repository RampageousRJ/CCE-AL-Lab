#include <iostream>
using namespace std;

int max(int arr[],int start,int end){
    if(start==end){
        return arr[start];
    }
    else if(start==end-1){
        return arr[start]>arr[end]?arr[start]:arr[end];
    }
    else{
        int mid = (start+end)/2;
        int m1 = max(arr,start,mid);
        int m2 = max(arr,mid+1,end);
        return m1>m2?m1:m2;
    }
}

int min(int arr[],int start,int end){
    if(start==end){
        return arr[start];
    }
    else if(start==end-1){
        return arr[start]<arr[end]?arr[start]:arr[end];
    }
    else{
        int mid = (start+end)/2;
        int m1 = min(arr,start,mid);
        int m2 = min(arr,mid+1,end);
        return m1<m2?m1:m2;
    }
}

int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Maximum Element: "<<max(arr,0,n-1);
    cout<<"\nMinimum Element: "<<min(arr,0,n-1);
    return 0;
}