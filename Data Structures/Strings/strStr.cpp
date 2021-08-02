#include<bits/stdc++.h>
using namespace std;

    int strStr(string haystack, string needle) {
        int start=0;
        int end = needle[needle.size()-1];
        int i=0;
        int n = haystack.size();
        while(i<n){
            if(haystack[i]==needle[start]){
                start=i;
                // end=i;
                int j=i;
                while(i<n && needle[0]==haystack[i]){
                    cout<<j<<" j";
                    if(j==needle.size()) return start;
                    j++;
                    i++;
                }
                i=start;
            }
            i++;
            cout<<i<<" i"<<endl;
        }
        return -1;
    }

    int main()
    {
        string haystack = "a";
        string needle = "a";
        cout<<strStr(haystack,needle)<<endl;
    }