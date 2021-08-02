#include<iostream>
using namespace std;

int countSubstrings(string s){
    int n = s.size();
    int m = s.size();
    bool t[n][m];
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i==j){
                t[i][j]=true;
            }
        }
    }
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(j>=i){
                if(i==j||s[i]==s[i+1] || (s[i]==s[j] && t[i+1][j-1]==true)){
                    t[i][j]=true;
                }
                else t[i][j]=false;
            }
            else t[i][j]=false;
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<t[i][j]<<" ";
            if(t[i][j]==true)
            count++;
        }
        cout<<endl;
    }
    return count;
}

    int main()
    {
        string s ="hello";
        cout<<countSubstrings(s)<<endl;
        // for(int i=0;i<5;i++){
        //     for(int j=0;j<5;j++){
        //         if(j<i){
        //             cout<<0<<" ";
        //         }
        //         else
        //         cout<<1<<" ";
        //     }
        //     cout<<endl;
        // }
    }