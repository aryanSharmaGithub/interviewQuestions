#include<iostream>
#include<vector>
using namespace std;

    int firstMissingPositive1(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int checkerOne=0;
        int min=1;


        for(int i=0;i<nums.size();i++)
        {
            if(nums.at(i)>0)
            {
                if(nums.at(i)==min && i!=nums.size()-1)
                    min++;
                else if(nums.at(i)==min && i==nums.size()-1)
                    return nums.at(i+1);
                else if(i!=0 && nums.at(i)==nums.at(i-1) && i!=nums.size()-1)
                continue;
                else return min;
            }
        }
        return 1;
    }
int firstMissingPositive(vector<int> &nums)
{
    for(int i=0;i<nums.size();i++)
    {
        while(nums.at(i)>0 && nums.at(i)<=nums.size() &&  nums[nums[i] - 1] != nums[i])
        swap(nums.at(i),nums.at(nums.at(i)-1));
    }
    for(int i=0;i<nums.size();i++)
    {
        if(nums.at(i)!=i+1)
        return i+1;
    }
    return nums.size()+1;
}
int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    // arr.push_back(12);
    // arr.push_back(11);
    cout<<firstMissingPositive(arr);
}