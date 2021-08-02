#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

vector<int> removeDuplicates(vector<int> arr){
    vector<int> ans;
    if(arr.size()==1){
        return arr;
    }
    unordered_map<int,bool> m;
    for(int i=0;i<arr.size();i++){
        if(m.count(arr.at(i))==0){
            ans.push_back(arr.at(i));
        }
        m[arr.at(i)]=true;
    }

    return ans;
}

int main()
{
    vector<int> arr{1,5,3,674,2,-5,3,1,6,8,5,80,6,4,3};
    vector<int> ans = removeDuplicates(arr);
    for(int i =0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
}