#include<bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A) {
    if(A.size()==1) return 0; // When there are not even two numbers, what is the use

    vector<pair<int,int> > val; // To make pairs of val and indices

    for(int i=0;i<A.size();i++){
        val.push_back({A[i],i});
    }

    sort(val.begin(),val.end()); // Sorting based on first value
    // To store the max indices from right side so that we can see which values are smallest for max Value from right and then print their diff (arr[i]<=arr[j] bcz of sorting)
    int max_index[A.size()];
    int mx = INT_MIN; // Just to store the values after comparing.

    for(int i=A.size()-1;i>=0;i--){
        mx = max(mx, val[i].second);
        max_index[i] = mx;
    }
    
    //iterate vector pair and find max index from i to n
    // After we have all the max values from right to left, we will find the max Diff it will have from highest indice to lowest indice
    // suppose max Indice is 5, this means that there exist some other value before indice 5 which is less than the value at indice 5. If we keep on subtracting & comp, we will
    // Eventually find the max diff
    int mil_gaya = INT_MIN;
    for(int i=0;i<A.size()-1;i++){
        mil_gaya = max(mil_gaya, max_index[i] - val[i].second);
    }
    
    return mil_gaya;
}

int main()
{
    vector<int> A{3, 5, 4, 2};
    cout<<maximumGap(A)<<endl;
}