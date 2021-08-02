#include<bits/stdc++.h>
using namespace std;

string lexographicalMaximal(string s){
    string ans ="";
    for(int i=0;i<s.size();i++){
        string a = s.substr(i);
        ans = max(ans,a);
    }
    return ans;
}

int main()
{
    cout<<lexographicalMaximal("254")<<endl;
    // 2.66  // 2.33
}