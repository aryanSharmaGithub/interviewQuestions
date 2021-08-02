#include<iostream>
using namespace std;

void strRev(string s)
{
    if(s.length()==0)
    return;
    strRev(s.substr(1));
    cout<<s[0];
}

int main()
{
    string s="aryan";
    strRev(s);
}