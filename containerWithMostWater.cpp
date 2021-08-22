#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> height){
    int l = 0, r = height.size()-1;
    int maxA = INT_MIN;
    int area;
    while(l<r){
        int tempAns = 0;
        int minHeight = min(height[l],height[r]);
        tempAns = (r-l)*minHeight;
        maxA = max(maxA,tempAns);
        if(height[l]<height[r]) l++; else r--;
    }
    return maxA;
}

int main()
{
    vector<int> height{4,3,2,1,4};
    cout<<maxArea(height)<<endl;
}