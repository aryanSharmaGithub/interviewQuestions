    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        sum = sum/2;
        vector<vector<int> > t(n+1,vector<int>(sum+1,0));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums.at(i-1)<=sum) 
                    t[i][j]=t[i-1][j] || t[i-1][j-nums[i-1]];
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
    }