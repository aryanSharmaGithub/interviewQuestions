#include<iostream>
#include<string>
using namespace std;
string st;
bool isValid(int k){
    int arr[4]={0};
    for(int i=0;i<k-1;i++){
        int idx = st[i]-'0';
        arr[idx]++;
    }

    for(int i=k-1;i<st.size();i++){
        int idx = st[i] - '0';
        arr[idx]++;
        if(arr[1]>0 && arr[2]>0 && arr[3]>0) return true;
        idx = st[i-k+1] - '0';
        arr[idx]--;
    }
    return false;
}

int getAns()
{
    int res = INT_MAX;
    int l = 3;
    int r = st.size();
    while(l<=r){
        int mid = l - (l-r)/2;
        if(isValid(mid)){
            res = min(res,mid);
            r = mid-1;
        }else l = mid+1;
    }
    if(res==INT_MAX) return 0;
    else return res;
}

int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--){
        cin>>st;
        cout<<getAns()<<endl;
    }
    // st = "123";
    // cout<<getAns()<<endl;
}