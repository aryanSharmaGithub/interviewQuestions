#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleInHistogram(vector<int> arr){
    arr.push_back(0);
    int n =arr.size();
    stack<int> st;
    int ans=0;
    int i=0;
    while(i<n){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            int h = arr[st.top()];
            st.pop();
            if(st.empty()){
                ans = max(ans,h*i);
            }
            else{
                int len = i-1-st.top();
                ans = max(ans,len*h);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{
    vector<int> arr{2,1,5,6,2,3};
    cout<<largestRectangleInHistogram(arr)<<endl;
}