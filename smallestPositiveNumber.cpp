#include<iostream>
using namespace std;

int smallestPositiveNumber(int arr[],int n)
{
    if(n==1 && arr[0]!=0)
    return 0;
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
        max=arr[i];
    }
    bool check[max];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        {
            check[arr[i]]=true;
        }
    }
    for(int i=0;i<max;i++)
    {
        if(check[i]==false)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int arr[]={2,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<smallestPositiveNumber(arr,n)<<endl;
}