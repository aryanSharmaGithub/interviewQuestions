#include<iostream>
using namespace std;

void merge(int arr[],int left, int right, int mid){
    int n1 = mid-left+1;
    int n2 = right - mid;
    
   

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[left+i];
    }

    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int i=0, j=0,key=left;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[key]=a[i];
            key++;
            i++;
        }
        else{
            arr[key]=b[j];
            key++;
            j++;
        }
    }

    while(i<n1){
        arr[key]=a[i];
        key++;
        i++;
    }
    while(j<n2){
        arr[key]=b[j];
        key++;
        j++;
    }

}

void mergeSort(int arr[],int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,end,mid);
    }    
}

int main()
{
    int arr[]={2,1,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}