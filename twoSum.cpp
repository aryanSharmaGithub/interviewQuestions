#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    vector<int> ans;
    map<int,int> arr;

    for(int i=0;i<nums.size();i++){
        if(arr.find(target - nums.at(i))!=arr.end()){
            ans.push_back(arr[target-nums.at(i)]);
            ans.push_back(i);
            return ans;
        }
        else arr.insert({nums.at(i),i});
    }
    return ans;
}

int main()
{
    vector<int> arr{2,7,11,15};
    vector<int> ans = twoSum(arr,9);
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
}
