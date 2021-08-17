    int depthSumInverse(vector<NestedInteger> nestedList) {
        int len = nestedList.size();
        // corner case
        if(len==0) {
            return 0;
        }
        // initialize
        int preSum=0;
        int result=0;
        // put each item of list into the queue
        queue<NestedInteger> q;
        for(int i=0;i<len;i++) {
            q.push(nestedList[i]);
        }
        
        while(!q.empty()){
            //depends on different depth, queue size is changeable
            int size = q.size();
            int levelSum = 0;
            for(int i = 0; i < size; i++){
                NestedInteger t = q.front();
                q.pop();
                if(t.isInteger())
                    levelSum += t.getInteger();
                else{
                    // depends on different depth, queue size is changeable
                    for(auto it:t.getList())
                        q.push(it);
                }
            }
            preSum += levelSum;
            result += preSum;
        }
        return result;
    }