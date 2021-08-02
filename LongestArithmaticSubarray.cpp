#include<iostream>
#include<vector>
using namespace std;

int longestArithmaticSubarray(int arr[],int n)
{
    int v[n];
    for(int i=0;i<n;i++)
    {
        v[i]=-1;
    }
    int max=INT_MIN;
    int count=0;
    int j=0;
    int diff=(arr[0]-arr[1]);
    for(int i=0;i<n-1;i++)
    {
        if(diff==(arr[i]-arr[i+1]))
        {
            count++;
            v[j]=count;
        }
        else
        {
            diff=arr[i]-arr[i+1];
            j++;
            count=0;
            count++;
            v[j]=count;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(max<v[i])
        max=v[i];
    }
    return max+1;
}

int main()
{
    int arr[]={9,4,-1,-6,5,8,11,14,17};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<longestArithmaticSubarray(arr,n)<<endl;
}