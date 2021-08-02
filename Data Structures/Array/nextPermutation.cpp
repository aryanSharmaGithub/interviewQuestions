#include<bits/stdc++.h>
using namespace std;

    void nextPermutation(vector<int>& arr) {
        int breakPoint=0, revVal=arr.size()-1;
        int n = arr.size();
        
        for(int i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                //cout<<"Check"<<endl;
                breakPoint = i-1;
                break;
            }    
        }
        
        for(int i=n-1;i>0;i--){
            if(arr[i]>arr[breakPoint]){
                revVal = i;
                //cout<<"Check"<<endl;
                //cout<<arr[breakPoint]<<" "<<arr[revVal]<<endl;
                swap(arr[breakPoint],arr[revVal]);
                //cout<<arr[breakPoint]<<" "<<arr[revVal]<<endl;
                break;
            }
        }
        
        reverse(arr.begin()+breakPoint+1,arr.end());
    }

int main()
{
    vector<int> arr{1,5,1};
    nextPermutation(arr);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}