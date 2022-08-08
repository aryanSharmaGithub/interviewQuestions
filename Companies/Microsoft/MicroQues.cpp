// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

string f(string t, string s){
    int n = t.size();
    int m = s.size();
    if(m>n) return "";

    string ans = "";

    string sortedS = s;
    sort(sortedS.begin(),sortedS.end());

    for(int i=0;i<n-m+1;i++){
        string subT = t.substr(i,m);
        sort(subT.begin(),subT.end());
        // if(tolower(sortedS) == tolower(subT)){
        //     ans = max(ans,t.substr(i,n));
        // }
        // if(strcasecmp(subT,sortedS)==0){
        //     ans = max(ans,t.substr(i,n));
        // }
        if(sortedS == subT){
            reverse(subT.begin(),subT.end());
            return subT;
        }
    }

    return ans;
}

int main()
{
    string t = "eatflehrawteahgrss";
    string s = "ate";
    cout<<f(t,s)<<endl;
}