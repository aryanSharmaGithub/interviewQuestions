#include<iostream>
using namespace std;

void printAllSubarray(int arr[],int n)
{
    int start,end;
    for(start=0;start<n;start++)
    {
        for(end=start;end<n;end++)
        {
            for(int k=start;k<=end;k++)
            {
                cout<<arr[k]<<" ,";
            }
            cout<<endl;
        }
    }
}

int main()
{
    int arr[]={-1,4,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printAllSubarray(arr,n);
}