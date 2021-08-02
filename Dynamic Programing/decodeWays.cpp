#include<bits/stdc++.h>
using namespace std;

    int numDecodings(string s) {
        if(s.size()==0 || s[0]=='0') return 0;
        if(s.length()==1) return 1;
        
        int count1 = 1, count2 = 1;
        for(int i=1;i<s.size();i++){
            int singleDigit = s[i]-'0';
            int doubleDigit = (s[i-1]-'0')*10 + singleDigit;
            int count = 0;
            // count+=count2 in single digit as it is surely to be true. If it is false, so will be double digit. So, becasue we have more
            // Dependence on 1 digit, we use count2 here (as it is the main tracker of prev count due to the statement count2 = count)
            if(singleDigit>0) count+=count2;
            if(doubleDigit>=10 && doubleDigit<=26) count+=count1;
            count1 = count2;
            count2 = count;
        }
        
        return count2;
    }

int main()
{
    string s = "123219";
    cout<<numDecodings(s)<<endl;
}