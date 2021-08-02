//Answer is unanswered for Leetcode. Will come again here

#include<iostream>
#include<vector>
using namespace std;

int smallestPositiveMissingNumber(vector<int>nums)
{
        //Check for all negative
        int flag =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums.at(i)>0)
            {
                flag=1;
                break;
            }
        }
        if(flag == 0)
            return 1;
        
        int maxNumber = *max_element(nums.begin(),nums.end());
        vector<int> checkAns(maxNumber,-1);
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums.at(i)>0)
            checkAns.at(nums.at(i)-1)=1;
        }
        
        for(int i=0;i<checkAns.size();i++)
        {
            if(checkAns.at(i)==-1)
                return i+1;
        }
        return maxNumber+1;
}

int main()
{
    // int arr[]={3,52,145,6432,1,8,9};
    // int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2147483647);
    nums.push_back(0);

    cout<<smallestPositiveMissingNumber(nums)<<endl;
}