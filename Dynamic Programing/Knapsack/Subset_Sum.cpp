#include<iostream>
using namespace std;

bool subset(int arr[], int n, int key)
{
    int t[n+1][key+1];
    //Initialisation
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<key+1;j++)
        {
            if(i==0 && j==0)
            t[i][j]= true;
            if(i==0)
            {
                t[i][j]= false;
            }
            if(j==0)
            {
                t[i][j]= true;
            }
        }
    }
    
    //Code
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<key+1;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][key];
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<subset(arr,n,29)<<endl;
    return 0;
}