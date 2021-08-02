#include<iostream>
#include<vector>
using namespace std;

bool sortArray(int arr[],int n)
{
    if(n==1)
    return true;
    if(arr[n]>arr[n-1])
    {
        sortArray(arr,n-1);
        return true;
    }
    return false;
}

int main()
{
    int arr[]={1,2,3,4,5,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<sortArray(arr,n)<<endl;
}