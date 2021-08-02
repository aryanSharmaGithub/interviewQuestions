#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > solve(vector<vector<int> > &a){
    int n = a.size();
    int m = a[0].size();
    for(int i=0;i<n;i++){
        for(int j=i;j<m;j++){
            swap(a[i][j],a[j][i]);
        }
    }

    // Reversing

    for(int i=0;i<m;i++){
        int end = n-1;
        int start = 0;
        while(start<end){
            swap(a[start][i],a[end][i]);
            start++; end--;
        }
    }
    return a;
}

int main()
{
    vector<vector<int> > a{{1,2},{4,5},{7,8}};
    vector<vector<int> >ans = solve(a);
    for(auto i: ans){
        for(auto j: i) cout<<j<<" ";
        cout<<"\n";
    }
}