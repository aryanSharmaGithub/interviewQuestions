#include<iostream>
#include<string>
using namespace std;

int mostFrequentChar(string s)
{
    int tempMax=0;
    sort(s.begin(),s.end());
    cout<<s<<endl;
    int maxFreq=INT_MIN;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            tempMax++;
            maxFreq=max(maxFreq,tempMax);
        }
        else tempMax=0;
    }
    return maxFreq+1;
}

int main()
{
    string s = "dslafjdsfkjdsflkajdf";
    cout<<mostFrequentChar(s)<<endl;
}