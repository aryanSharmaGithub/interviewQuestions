#include<iostream>
using namespace std;

string moveX(string s)
{
    if(s.length()==0)
    return "";

    char first=s[0];
    string ans = moveX(s.substr(1));
    if(first=='x')
    {
        return ans+first;
    }
    else return first+ans;
}

int main()
{
    string s = "cmxbznzbmcxncbxbcxnmzbncmxz";
    cout<<moveX(s)<<endl;
}