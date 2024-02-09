#include <iostream>
using namespace std;

int count=0;
int binarySearch(int arr[],int n,int ele){
    int start=0,last=n-1;
    count++;
    do{
        int mid=(start+last)/2;
        count++;
        count++;
        if(arr[mid]==ele){
            count++;
            return mid;
        }
        else{count++; if(ele<arr[mid]){
            last=mid-1;
            count++;
        }
        else{
            count++;
            start=mid+1;
            count++;
        }}
    }while(start<=last);
    count++;
    count++;
    return -1;
}

int main(){
    int n,ele;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Input array: \n";
    for(int j=0;j<n;j++){
        arr[j]=j+1;
    }
    //arr[(n-1)/2]=0;
    int ind=binarySearch(arr,n,0);
    if(ind>-1){
        cout<<"Element found at "<<ind;
    }
    else{
        cout<<"Element not found";
    }
    cout<<"\n\nStep count: "<<count;
}
