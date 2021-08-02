#include<bits/stdc++.h>
using namespace std;

vector<int>subUnsort(vector<int> &A) {
    vector<int> ans;
    int n = A.size();
    int minVal = INT_MAX, maxVal = INT_MIN;
    
    for(int i=0; i<n-1; i++){
        if(A[i]>A[i+1]) minVal = min(A[i+1],minVal);
    }
    
    for(int i=n-1;i>0;i--){
        if(A[i-1]>A[i]) maxVal = max(A[i-1],maxVal);
    }
    
    if(minVal==INT_MAX && maxVal == INT_MIN) return {-1};
    
    int start = 0, end = n-1;
    
    for(;start<n;start++) if(A[start]>minVal) break;
    for(;end>=0;end--) if(A[end]<maxVal) break;
    
        ans.push_back(start);
        ans.push_back(end);
        
        return ans;
}

int main()
{
    vector<int> A{2,6,4,8,10,9,15};
    vector<int> ans = subUnsort(A);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
}