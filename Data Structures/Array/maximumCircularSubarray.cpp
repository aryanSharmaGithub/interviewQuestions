#include<iostream>
#include<vector>
using namespace std;


int maximumSubarray(vector<int> nums)
{
    int ans,flag,currentSum;
    int maxSum =INT_MIN;
    int n=nums.size();
    if(n==1)
    return nums.at(0);

    //Check if any positive is present
    for(int i=0;i<n;i++)
    {
        if(nums.at(i)>0)
        flag =1;
    }

    for(int i=0;i<n;i++)
    {
        if(flag==1)
        {
            currentSum+=nums.at(i);
            if(currentSum<0)
            currentSum=0;
            maxSum=max(maxSum,currentSum);
        }
        else maxSum=max(maxSum,nums.at(i));
    }
    return maxSum;

}

int maximumCircularSubarray(vector<int> &nums)
{
    // Max subarray sum = sum of all elements - sum of non containing elements
    // sum of non containing elements = kadens algorithm on array with reverse sign
    int n= nums.size();
    int originalSum =0;
    int ans = 0, negativeAns=INT_MIN;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(nums.at(i)>0)
        flag=1;
    }
    int nonWrapans = maximumSubarray(nums);
    for(int i=0;i<n;i++)
    {
        if(flag==1)
        {
            originalSum+=nums.at(i);
            nums.at(i)*=-1;
        }
        else negativeAns=max(negativeAns,nums.at(i));
    }
    if(flag==1)
    {
        ans = originalSum + maximumSubarray(nums);
        return max(ans,nonWrapans);
    }
    else
    return negativeAns;
}

int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(-2);
    nums.push_back(5);
    // nums.push_back(-2);
    cout<<maximumCircularSubarray(nums)<<endl;
}