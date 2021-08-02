#include<iostream>
using namespace std;

void subArrayWithGivenSum(int arr[],int n,int sum)
{
    int currentSum=0;
    int start=0,end=0;
    while(currentSum<=sum)
    {
        currentSum+=arr[end];
        end++;
        if(currentSum==sum)
        {
            cout<<start<<" "<<end<<endl;
            return;
        }
    }

    while(currentSum!=sum)
    {
        currentSum-=arr[start];
        start++;
    }
    cout<<start<<" "<<end-1<<endl;
}

int main()
{
    int arr[]={1,2,3,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    subArrayWithGivenSum(arr,n,12);
}