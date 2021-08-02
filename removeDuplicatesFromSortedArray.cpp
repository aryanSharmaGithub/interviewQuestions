#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &A) {
    if(A.size()==1){
        return 1;
    }
    int curr=0;
    for(int i=0;i<A.size()-1;i++){
        if(A[i+1]!=A[i]){
            curr++;
            A[curr]=A[i+1];
        }
    }
    A.erase(A.begin()+curr+1,A.end());
    return A.size();
}

int main()
{
    vector<int> A{1,2,4,4,5,6};
    cout<<removeDuplicates(A)<<endl;
    for(auto i:A){
        cout<<i<<" ";
    }
    cout<<endl;
}