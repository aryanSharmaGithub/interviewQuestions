#include<iostream>
#include<vector>
using namespace std;

struct Job
{
    /* data */
    int dead;
    int profit;
};


    static bool compare(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int sum = 0;
        int item=0;
        int fill[n];
        memset(fill,0,sizeof(fill));
        sort(arr,arr+n,compare);
        for(int i=0;i<n;i++)
        {
            int pos=arr[i].dead-1;
            if(fill[pos]==0)
            {
                fill[pos]=1;
                sum+=arr[i].profit;
                item++;
            }
            else
            {
                while(pos!=0)
                {
                    pos--;
                    if(fill[pos]==0)
                    {
                        fill[pos]=1;
                        sum+=arr[i].profit;
                        item++;
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        ans.push_back(item);
        ans.push_back(sum);
        return ans;
    } 

int main()
{
    Job arr[5];
    int w=100;
    for(int i =0;i<4;i++){
        arr[i].dead=5-i;
        arr[i].profit=w;
        w-=10;
    }
    arr[4].dead = 1;
    arr[4].profit = 1000;
    vector<int> ans = JobScheduling(arr,5);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}