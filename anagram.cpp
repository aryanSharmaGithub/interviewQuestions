#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > anagrams(const vector<string> &a) {
    unordered_map<string,vector<int> >m;
    for(int i=0;i<a.size();i++){
        string s=a[i];
        sort(s.begin(),s.end());
       
        m[s].push_back(i+1);
    }
    vector<vector<int> >ans;
    for(auto x: m){
        ans.push_back(x.second);
    }
    return ans;
}

int main()
{
    vector<string> ans {"cat", "dog", "god", "tca"};
    vector<vector<int> > lol = anagrams(ans);
    for(int i=0;i<lol.size();i++){
        for(int j=0;j<lol[i].size();j++){
            cout<<lol[i][j]<<" ";
        }
        cout<<endl;
    }
}