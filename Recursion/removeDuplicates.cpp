#include<iostream>

using namespace std;

string removeDuplication(string s)
{
    if(s.length()==0)
    return "";

    char first = s[0];
    string ans = removeDuplication(s.substr(1));
    if(ans[0]==s[0])
    return ans;
    else return first+ans;
}

int main()
{
    string s = "aaaaaakkkkkkkdddddddlllllliiiiiiee";
    cout<<removeDuplication(s)<<endl;
}