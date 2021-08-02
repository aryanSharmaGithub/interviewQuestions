#include<iostream>
#include<vector>
using namespace std;

int activitySelection(vector<vector<int> > time){
    // Dont know how this sort works. Just a function
    sort(time.begin(),time.end(),[&](vector<int> &a,vector<int> &b){
        return a[1] < b[1];
    });
    int task =1;
    int end = time[0][1];
    for(int i = 1;i<time.size();i++){
        if(time[i][0]>=end){
            task++;
            end= time[i][1];
        }
    }
    return task;
}

int main()
{
    vector<vector<int> > time;
    time.push_back({10,20});
    time.push_back({12,15});
    time.push_back({20,30});
    cout<<activitySelection(time)<<endl;
    return 0;
}