#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > ans;
// This will happen when our array will have scanned all the values it can scan (so if we have 3 elements, we would have scanned all 3 of them to push inside ans arr)
void permutation(vector<int> a, int index = 0){ 
    if(index == a.size()){
        ans.push_back(a);
        return;
    }

// Here we will do the purmutation until we reach the last element in array
    for(int i = index; i<a.size();i++){
        swap(a[i],a[index]); // We will swap the element in our array with the element after the array (like in 1,2,3 we will swap 2 with 3, 1 with 2,3)
        permutation(a,index+1); // We will store the ans here (it will keep on increasing till index != a.size where it means perm is done and ans can be pushed)
        swap(a[i],a[index]); // This will reverse the array again to its original form (because this is called backtracking tho idk why is it useful here)
    }

}

int main()
{
    vector <int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    // a.push_back(4);
    // a.push_back(5);
    // a.push_back(6);
    // a.push_back(7);
    permutation(a);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}