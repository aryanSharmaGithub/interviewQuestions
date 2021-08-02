#include<iostream>
#include<vector>
using namespace std;

    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans(numRows); // Ans array
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1); // This will increase the size of array in vector to 1 greater than the level
            // because every level has 1 + level elements like level 0 has 1, 1 has 2 etc
            ans[i][0]=ans[i][i]=1; // Making the first and last element as 1 (a[i][i] means 3 levels 3rd element but as indices go from 0 to n-1, it cancels out)
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j]; // One above left and one directly above
            }
        }
        return ans;
    }

int main()
{
    vector<vector<int> > ans = generate(5);
    for(int i =0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}