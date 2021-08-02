#include<iostream>
#include<vector>
using namespace std;

int firstOcc(int arr[],int n,int x)
{
    int static i =0;
    if(n==-1)
    return 0;
    if(arr[0]==x)
    {
        return i;
    }
    else{
        i++;
        return firstOcc(arr+1,n-1,x);
    }
}

int lastOcc(int arr[],int n,int x){
    if(n==-1)
    return 0;
    //int static i=n;
    if(arr[n]==x)
    {
        return n;
    }
    else{
        //i--;
        return lastOcc(arr,n-1,x);
    }
}

int main()
{
    int arr[]={1,3,4,4,5,6,3,2,5,6,7,8,4,3,2,8,9,8,7,6,5,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<firstOcc(arr,n,4);
    cout<<endl;
    cout<<lastOcc(arr,n,4);
    cout<<endl;
}