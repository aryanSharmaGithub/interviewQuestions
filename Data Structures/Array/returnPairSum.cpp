#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &nums,int target)
{
    vector<int> ans;
    sort(nums.begin(),nums.end());
    int start=0,end = nums.size()-1;
    int low = nums.at(start);
    int high = nums.at(end);
    for(int i=0;i<nums.size();i++)
    {
        if(high+low==target)
        {
            ans.push_back(low);
            ans.push_back(high);
            return ans;
        }
        else if(high+low>target)
        high = nums.at(end--);
        else low = nums.at(start++);
    }
    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    // nums.push_back();
    // nums.push_back();
    vector<int>ans=twoSum(nums,9);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans.at(i)<<" ";
    }
}