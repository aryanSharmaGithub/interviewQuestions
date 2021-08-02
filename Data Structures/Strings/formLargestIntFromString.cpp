#include<iostream>
#include<string>
using namespace std;

string formLargestInt(string s)
{
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    string s = "945387";
    cout<<formLargestInt(s)<<endl;
}