#include<iostream>
#include<vector>
using namespace std;


    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums.at(0);
        int flag =0;
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)>0)
                flag=1;
        }
        int maxSum = INT_MIN;
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            if(flag == 1){
                currSum+=nums[i];
                if(currSum<0){
                    currSum=0;
                }
                maxSum = max(maxSum,currSum);
            }
            else maxSum = max(maxSum,nums.at(i));
        }
        return maxSum;
    }
    // int maxSubArray(vector<int>& nums)
    // {
    //     int ans=nums[0],i,j,sum=0;
    //     for(i=0;i<nums.size();i++){
    //         sum+=nums[i];
    //         ans=max(sum,ans);
    //         sum=max(sum,0);
    //     }
    //     return ans;
    // }

int main()
{
    vector <int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    cout<<maxSubArray(nums);
}