#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> m;
        bool isPresent = false;
        for(auto i: wordList){
            if(endWord==i) isPresent =true;
            m.insert(i);
        }
        if(!isPresent) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while(!q.empty()){
            depth+=1;
            int lSize = q.size();
            while(lSize--){
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.length();i++){
                    string temp = curr;
                    for(char c = 'a'; c<='z';c++){
                        temp[i]=c;
                        if(curr==temp) continue;
                        if(m.find(temp)!=m.end()){
                            if(temp==endWord) return depth+1;
                            q.push(temp);
                            m.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }

    int main()
    {
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> ans{"hot","dot","dog","lot","log","cog"};
        cout<<ladderLength(beginWord,endWord,ans)<<endl;
    }