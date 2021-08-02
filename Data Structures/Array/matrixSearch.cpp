#include<iostream>
using namespace std;

bool matrixSearch(int arr[][4],int key)
{
    int i=0,j=3;
    while(arr[i][j]!=key && i<4 && j>-1)
    {
        if(arr[i][j]>key)
        {
            // cout<<arr[i][j]<<" ";
            j--;
        }
        
        if(arr[i][j]<key)
        {
            // cout<<arr[i][j]<<" ";
            i++;
        }

        if(arr[i][j]==key)
        {
            // cout<<arr[i][j]<<" ";
            return true;
        }
    }
    return false;
}

int main()
{ 
    int arr[4][4]={{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};
    cout<<matrixSearch(arr,5)<<endl;
    cout<<matrixSearch(arr,20)<<endl;
}