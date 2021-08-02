#include<bits/stdc++.h>
using namespace std;

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n,1);
        int maximum = 1;
        for(int i=1;i<nums.size();i++){
            int maxVal = 0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    maxVal = max(maxVal,t[j]);
                }
            }
            t[i]=maxVal+1;
            maximum = max(maximum,t[i]);
        }
        return maximum;
    }

    int main()
    {
        vector<int> nums{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
        cout<<lengthOfLIS(nums)<<endl;
    }