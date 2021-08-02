#include<iostream>
#include"map"
#include<unordered_map>
using namespace std;
int main()
{
    int arr[]={1,3,5,4,5,3,4,6,5,6,4,4,5,2,2,3,4,3,3,2,4,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    map<int, int> m; //First is element and second is frequency
    // for(int i=0;i<n;i++){
    //     freq[arr[i]]++;
    // }

    // map<int,int> :: iterator it;
    // for(it=freq.begin();it!=freq.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    int maxFreq =1;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
        maxFreq = max(maxFreq,m.at(arr[i]));
    }
    cout<< maxFreq<<endl;

}