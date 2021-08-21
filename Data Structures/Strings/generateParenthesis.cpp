#include<bits/stdc++.h>
using namespace std;

void help(vector<string> &ans, string curr, int left, int right, int max){
    if(curr.size()==2*max){
        ans.push_back(curr);
        return;
    }
    if(left<max){
        curr.push_back('(');
        help(ans,curr,left+1,right,max);
        curr.pop_back();
    }
    if(right<left){
        curr.push_back(')');
        help(ans,curr,left,right+1,max);
        curr.pop_back();
    }
}

vector<string> generateParenthesis(int n){
    string temp = "";
    vector<string> ans;
    help(ans,temp,0,0,n);
    return ans;
}

int main()
{
    vector<string> ans = generateParenthesis(3);
    for(auto i: ans) cout<<i<<" ";
    cout<<endl;
}