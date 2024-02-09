#include <iostream>
using namespace std;
int count=0;

int binarysearch(int arr[],int start,int end,int key){
    int mid=(start+end)/2;
    count+=2;
    count++;
    if(key==arr[mid]){
        count++;
        return mid;
    }
    count++;
    if(key>arr[mid]){
        count++;
        return binarysearch(arr,mid+1,end,key);
    }
    count++;
    if(key<arr[mid]){
        count++;
        return binarysearch(arr,start,mid-1,key);
    }
    else{
        count++;
        return -1;
    }
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n+1];
    for(int j=0;j<n;j++){
        arr[j]=0;
    }
    int ind=binarysearch(arr,arr[0],arr[n-1],1);
    if(ind>-1){
        cout<<"Element found at "<<ind;
    }
    else{
        cout<<"Element not found";
    }
    cout<<"\n\nStep count: "<<count;
    return 0;
}