#include<iostream>
using namespace std;

int maximumSubarraySum(int arr[],int n)
{
        if(n==1)
            return arr[0];
        int currentSum = 0;
        int maxSum = INT_MIN;
        int flag = 0;
        //Check if array has any positive value or not
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
                flag =1;
        }
        for(int i=0;i<n;i++)
        {
            if(flag==1)
            {
                currentSum+=arr[i];
                if(currentSum<0)
                currentSum=0;
                maxSum=max(maxSum,currentSum);
            }
            else maxSum=max(maxSum,arr[i]);
        }
        return maxSum;
}

int main()
{
    int arr[]={5,4,-1,7,8};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<maximumSubarraySum(arr,n)<<endl;
}