#include<bits/stdc++.h>
using namespace std;

    int minCost(vector<vector<int>> &costs) {
        if(costs.size()==0) return 0;
        int n = costs.size();
        vector<vector<int> > t(n,vector<int>(3,0));
        t[0][0]=costs[0][0];
        t[0][1]=costs[0][1];
        t[0][2]=costs[0][2];
        for(int i=1;i<n;i++){
            t[i][0]=min(t[i-1][1],t[i-1][2]) + costs[i][0];
            t[i][1]=min(t[i-1][0],t[i-1][2]) + costs[i][1];
            t[i][2]=min(t[i-1][0],t[i-1][1]) + costs[i][2];
        }
        return min(t[n-1][0],min(t[n-1][1],t[n-1][2]));
    }

    int main()
    {
        vector<vector<int> > cost = {{1,2,3},{4,5,6},{7,8,9}};
        cout<<minCost(cost)<<endl;
    }