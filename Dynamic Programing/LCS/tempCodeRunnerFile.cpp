#include<iostream>
#include<vector>
using namespace std;

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int t[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0||j==0)
                {
                    t[i][j]=0;
                    cout<<t[i][j]<<" ";
                    continue;
                }    
                if(j<n-i+1)
                {
                    if(nums.at(i-1)<nums.at(i+j-1) && (i+j)<=n)
                    {
                        t[i][j]=1+t[i-1][j-1];
                        cout<<t[i][j]<<" ";
                    }    
                    else if(nums.at(i-1)==nums.at(i+j-1) && (i+j)<=n)
                    {
                        t[i][j]=1;
                        cout<<t[i][j]<<" ";
                    }
                    else
                    {
                        t[i][j]=0;
                        cout<<t[i][j]<<" ";
                    }
                }
            }
            cout<<endl;
        }
        return t[n][n];
    }

int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(3);
    // arr.push_back(101);
    // arr.push_back(18);
    cout<<lengthOfLIS(arr)<<endl;
}