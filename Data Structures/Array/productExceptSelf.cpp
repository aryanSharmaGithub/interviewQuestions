#include<bits/stdc++.h>
using namespace std;

    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==1) return {0};
        
        vector<int> ans(nums.size(),1);

        for(int i=1;i<nums.size();i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int rightVal = 1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=rightVal;
            rightVal *= nums[i];
        }
        
        return ans;
    }

int main()
{
    vector<int> nums{1,2,3,4};
    vector<int> ans = productExceptSelf(nums);
    for(auto i: ans) cout<<i<<" ";
    cout<<endl;
}