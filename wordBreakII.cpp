#include<bits/stdc++.h>
using namespace std;

    vector<string> help(int start, string s, unordered_set<string> dict){
        vector<string> subStr;
        if(start==s.length()) subStr.push_back("");
        
        for(int end = start+1;end<=s.size();end++){
            string prefix = s.substr(start,end);
            if(dict.find(prefix)!=dict.end()){
                vector<string> suffixes = help(end,s,dict);
                for(string suffix : suffixes){
                    subStr.push_back(prefix);
                    if(suffix=="") subStr.push_back("");
                    else subStr.push_back(" ");
                    subStr.push_back(suffix);
                }
            }
        }
       return subStr; 
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m;
        for(int i=0;i<wordDict.size();i++) m.insert(wordDict[i]);
        return help(0,s,m);
    }

int main()
{
    string s = "catsanddog";
    vector<string> wordDict{"cat","cats","and","sand","dog"};
    vector<string> ans = wordBreak(s,wordDict);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
}