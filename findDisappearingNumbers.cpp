#include<iostream>
#include<vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
        // sort(nums.begin(),nums.end());
        // vector <int> missingNumber;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]!=i+1)
        //     {
        //         missingNumber.push_back(i+1);
        //     }
        // }
        // return missingNumber;
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
}
int main()
{
   vector<int> initNumbers;
   initNumbers.push_back(4);
   initNumbers.push_back(3);
   initNumbers.push_back(6);
   initNumbers.push_back(1);
   initNumbers.push_back(5);

    findDisappearedNumbers(initNumbers);

}