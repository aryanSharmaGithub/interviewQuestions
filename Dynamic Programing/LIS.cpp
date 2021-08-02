#include<bits/stdc++.h>
using namespace std;

int bitonicSubsequence(vector<int> a){
    int n = a.size();
    vector<int> incArr(n,1);
    vector<int> decArr(n,1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]) incArr[i]=max(incArr[i],1+incArr[j]);
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j]) decArr[i]=max(decArr[i],1+decArr[j]);
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        int len = 2*(min(incArr[i],decArr[i]))-1;
        ans = max(ans,len);
    }

    return ans;
}

int main()
{
    vector<int> arr{1 ,2 ,3 ,2 ,1 ,4 ,5 ,6 ,7 ,19 ,15 ,12, 10, 9};
    cout<<bitonicSubsequence(arr)<<endl;
}