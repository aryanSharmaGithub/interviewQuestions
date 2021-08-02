#include<bits/stdc++.h>
using namespace std;

    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > ans;
        if(intervals.size()==0) return ans;
        sort(intervals.begin(),intervals.end());
        vector<int>merge = intervals[0];
        for(auto it:intervals){
            if(merge[1]>=it[0]) merge[1]=max(merge[1],it[1]);
            else{
                ans.push_back(merge);
                merge = it;
            }
        }
        ans.push_back(merge);
        return ans;
    }

int main()
{
    // [[1,3],[2,6],[8,10],[15,18]]
    vector<vector<int> > a{{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int> > ans = merge(a);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;
}