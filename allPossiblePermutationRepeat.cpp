#include<iostream>
#include<vector>
using namespace std;

void helper(vector <int> a,vector<vector<int> > &ans, int idx){
    if(idx == a.size()){
        ans.push_back(a);
        return;
    }

    for(int i=idx;i<a.size();i++){
        if(i!=idx && a.at(i)==a.at(idx)){
            continue;
        }
        swap(a.at(i),a.at(idx));
        helper(a,ans,idx+1);
        // swap(a.at(i),a.at(idx));
    }
}

vector<vector<int> > permutation(vector <int> a, int idx = 0){
    sort(a.begin(),a.end());
    vector<vector<int> > ans;
    helper(a,ans,idx);
    return ans;
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);

    vector<vector<int> > ans = permutation(a);

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}