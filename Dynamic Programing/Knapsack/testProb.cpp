#include<iostream>
using namespace std;

    int climbStairs(int size) {
        int arr[size];
        if(size==1) return 1;
        arr[1]=1;
        arr[2]=2;
        // int t[n+1][size+1];
        // for(int i=0;i<n+1;i++)
        // {
        //     for(int j=0;j<size+1;j++)
        //     {
        //         if(i==0)
        //         {
        //             t[i][j]=0;
        //             //cout<<t[i][j]<<" ";
        //         }
        //         else if(j==0)
        //         {
        //             t[i][j]=1;
        //             //cout<<t[i][j]<<" ";
        //         }
        //         else if(arr[i-1]<=j)
        //             {
        //                 t[i][j]=t[i][j-arr[i-1]]+t[i-1][j];
        //                 //cout<<t[i][j]<<" ";
        //             }
        //         else
        //         {
        //             t[i][j]=t[i-1][j];
        //             //cout<<t[i][j]<<" ";
        //         }
        //     }
        //     //cout<<endl;
        // }
        // return t[n][size];
        for(int i=3;i<size+1;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[size];
    }


int main()
{
    int n=2;
    cout<<climbStairs(n)<<endl;
}