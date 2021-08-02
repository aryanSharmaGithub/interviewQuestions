#include<iostream>
using namespace std;

int countSubset(int arr[],int n, int sum)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                if(j==0)
                t[i][j]= 1;
                else t[i][j]=0;
            }
            if(j==0)
            t[i][j]=1;
        }
    }

    for(int i=1;i<n+1;i++)
    for(int j=1;j<sum+1;j++)
    {
        if(arr[i-1]<=j)
        {
            t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
        }
        else t[i][j]=t[i-1][j];
    }
    
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
    return t[n][sum];
}

int main()
{
    int arr[]={1,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<countSubset(arr,n,4)<<endl;
}