#include<iostream>
#include<vector>
using namespace std;

int firstRepeatingElement(int arr[],int n)
{
    if(n==1)
    return 1;
    int v[n+1];
    for(int i=0;i<n+1;i++)
    {
        v[i]=-1;
    }
    int minDiff=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(v[arr[i]]==-1)
        v[arr[i]]=i+1;
        else if(minDiff>v[arr[i]])
        minDiff=v[arr[i]];
        else continue;
    }
    return minDiff;
}

int main()
{
    int arr[]={1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<firstRepeatingElement(arr,n)<<endl;
}