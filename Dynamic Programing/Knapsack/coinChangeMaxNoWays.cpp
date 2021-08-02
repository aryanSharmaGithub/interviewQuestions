#include<iostream>
using namespace std;

int coinChangeMaxCount (int arr[], int n, int sum)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                if(j==0) t[i][j]=1;
                else t[i][j]=0;
            }
            else if(j==0)
            t[i][j]=1;
            else if(arr[i-1]<=j)
            {
                t[i][j]=t[i][j-arr[i-1]] + t[i-1][j];
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<coinChangeMaxCount(arr,n,18)<<endl;
}