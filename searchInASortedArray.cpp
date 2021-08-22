#include<bits/stdc++.h>
using namespace std;

int search(vector<int> nums, int target){
    int l = 0, r = nums.size()-1;
    while(l<=r){
        int mid = r + (l-r)/2;
        if(nums[mid]==target) return mid;
        if(nums[l]<=nums[mid]){
            if(nums[l]<=target && nums[mid]>=target){
                r = mid-1;
            }else l = mid+1;
        }else{
            if(nums[mid]<=target and nums[r]>=target) l = mid+1;
            else r = mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums{4,5,6,7,0,1,2};
    cout<<search(nums,0)<<endl;
}