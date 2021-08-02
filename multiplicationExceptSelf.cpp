#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector <int> &nums)
{
    int n=nums.size();
    vector <int> forwardMultiply(n,1);
    vector <int> backwardMultiply(n,1);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        forwardMultiply[i]=1;
        else
        forwardMultiply[i]=forwardMultiply[i-1]*nums[i-1];
    }

    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
        backwardMultiply[i]=1;
        else
        backwardMultiply[i]=backwardMultiply[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++)
    {
        nums[i]=forwardMultiply[i]*backwardMultiply[i];
    }
    return nums;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    productExceptSelf(arr);

}