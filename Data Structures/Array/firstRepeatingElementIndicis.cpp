#include<iostream>
#include<vector>
using namespace std;

int repeatingElement(int arr[],int n)
{
    int maxans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxans=max(maxans,arr[i]);
    }
    vector<int>checkArr(maxans+1,-1);
    int minIndex = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(checkArr.at(arr[i])!=-1)
        {
            minIndex=min(minIndex,checkArr.at(arr[i]));
        }
        checkArr.at(arr[i])=i+1;
    }
    return minIndex;
}

int main()
{
    int arr[]={1,5,3,4,3,5,6,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<repeatingElement(arr,n)<<endl;
}