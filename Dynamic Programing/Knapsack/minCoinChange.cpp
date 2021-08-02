#include<iostream>
using namespace std;

int minCoinChange(int arr[],int n, int sum)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        t[i][0]=0;
    }
    for (int j=0;j<sum+1;j++)
    {
        t[0][j]=INT_MAX-1;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            t[i][j]=min(1+t[i][j-arr[i-1]],t[i-1][j]);
            else t[i][j]=t[i-1][j];
        }
    }
    if(t[n][sum]==INT_MAX-1)
    return -1;
    else
    return t[n][sum];
    
}

int main()
{
    int arr[]={9, 6, 5, 4};
    int sum=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minCoinChange(arr,n,sum)<<endl;

}