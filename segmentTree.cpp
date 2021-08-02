#include<bits/stdc++.h>
using namespace std;

int getSum(int *st, int start, int end, int l, int r, int si){
    if(l<=start && r>=end){
        return st[si];
    }
    if(l>start || r<end){
        return 0;
    }
    int mid = start + (end - start)/2;
    return getSum(st,start,mid,l,r,2*si+1) + getSum(st,mid+1,end,l,r,2*si+2); 
}

int segmentTreeUtil(vector<int> arr, int start, int end, int *st, int si){ // start end is range of whole array while function is executed, st is the pointed in segment tree, si is segment tree index
    if(start==end){ //Leaf node
        st[si]= arr[start];
        return arr[start];
    }
    int mid = start - (start - end)/2;
    st[si]=segmentTreeUtil(arr,start,mid,st,si*2+1) + segmentTreeUtil(arr,mid+1,end,st,si*2+2);
    return st[si];
}

int *segmentTree(vector<int> arr, int n){
    int h = (int)(ceil(log2(n))); // Height = log2(n);
    int maxSize = 2*(int)pow(2,h)-1;
    int *st = new int[maxSize];
    segmentTreeUtil(arr,0,n-1,st,0);
    return st;
}

int main()
{
    vector<int> arr{1,5,2,4,8,23};
    int n = arr.size();
    int *st = segmentTree(arr,n);
    int sum1 = getSum(st,0,n-1,1,4,0);
    cout<<sum1<<endl;
}