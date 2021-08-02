#include<iostream>
#include<string>
using namespace std;

void isUpper(string &s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a' && s[i]<='z')
        s[i]-=32;
    }
    cout<<s<<endl;
}

void isLower(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        s[i]+=32;
    }
    cout<<s<<endl;
}

int main()
{
    string s="aBcDeFgHiJk";
    //Can be done like this too (toUpper)
    // transform(s.begin(),s.end(),s.begin(),::toupper);
    //Can be done like this too (toLower)
    // transform(s.begin(),s.end(),s.begin(),::tolower);
    isLower(s);
    isUpper(s);
}