#include<iostream>
#include<vector>
using namespace std;

vector <int> subsetSum(int arr[],int n, int range)
{
    vector<int>v;
    bool t[n+1][range+1];
    cout<<endl<<"Bottom Up table is:"<<endl;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<range+1;j++)
        {
            if(i==0)
            {
                if(j==0)
                {
                    t[i][j]=1;
                    cout<<t[i][j]<<" ";
                    continue;
                }
                else
                {
                    t[i][j]=0;
                    cout<<t[i][j]<<" ";
                    continue;
                }
            }
            if(j==0)
            {
                t[i][j]=1;
                cout<<t[i][j]<<" ";
                continue;
            }
            if(arr[i-1]<=j)
            t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            else
            t[i][j]=t[i-1][j];
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;
    cout<<"Last line of the table is: ";
    for(int j=0;j<range+1;j++)
    {
        cout<<t[n][j]<<" ";
        if((t[n][j]==true) && (j<range/2))
        v.push_back(j);
    }
    cout<<endl;
    return v;
}

int minSumSubDiff(int arr[], int n)
{
    int minmum=INT_MAX;
    int range=0;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        range+=arr[i];
    }
    v=subsetSum(arr,n,range);
    cout<<"S1 is any one of the following: ";
    for(int i=0;i<v.size();i++)
    {
        minmum=min(minmum,range-2*v.at(i));
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    cout<<"Minimum Sum Subset Difference is: ";
    return minmum;
}

    vector<int> subset(vector<int> nums, int range)
    {
        vector <int> inputs;
        bool t[nums.size()+1][range+1];
        for(int i=0;i<nums.size()+1;i++)
        {
            for(int j=0;j<range+1;j++)
            {
                if(i==0)
                {
                    t[i][j]=0;
                    continue;
                }
                if(j==0)
                {
                    t[i][j]=1;
                    continue;
                }    
                if(nums.at(i-1)<=j)
                    t[i][j]=t[i-1][j-nums.at(i-1)] || t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        }
        for(int j=0;j<range+1;j++)
        {
            if(t[nums.size()+1][j]== true && j<range/2)
                inputs.push_back(j);
        }
        return inputs;
    }
    
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)
            return nums.at(0);
        int minimum=INT_MAX;
        vector <int> v;
        int range=0;
        for(int i=0;i<nums.size();i++)
        {
            range+=nums.at(i);
            
        }
        cout<<range<<endl;
        v=subset(nums,range);
        for(int i=0;i<v.size();i++)
        {
            minimum=min(minimum,range-2*v.at(i));
        }
        return minimum;
    }

int main()
{
    // int arr[]={1,2,7};
    // int n=sizeof(arr)/sizeof(arr[0]);
    vector <int> arr;//{-2,1,-3,4,-1,2,1,-5,4}
    arr.push_back(-2);
    arr.push_back(1);
    arr.push_back(-3);
    arr.push_back(4);
    arr.push_back(-1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(-5);
    arr.push_back(4);

    cout<<maxSubArray(arr)<<endl;
}