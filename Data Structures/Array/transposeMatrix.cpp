#include<iostream>
#include<vector>
using namespace std;

void transpose(int arr[4][4])
{
    int temp=0;
    for(int i=0;i<4;i++)
    {
        for(int j=i;j<4;j++)
        {
            //if(i==0)
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    transpose(arr);
}