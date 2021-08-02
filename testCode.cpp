#include<bits/stdc++.h>
using namespace std;

int FY22CampusPaintTheWall(string wall, int k) {
    if(wall.size()==0) return 0;
    int maxVal = 1;
    int n = wall.size();
    for(int i=0;i<wall.size();i++){
        int j=i+1;
        int maxTemp =1;
        int tempK = k;
        while(j<n){
            if(wall[j]==wall[i]){
                maxTemp++;
            }
            else{
                tempK--;
                maxTemp++;
            }
            if(tempK<0){
                maxTemp--;    
                break;
            }
            j++;
        }
        maxVal = max(maxVal,maxTemp);
    }
    return maxVal;
}

int main()
{
    string wall = "abaab";
    int k = 1;
    cout<<FY22CampusPaintTheWall(wall,k)<<endl;
}