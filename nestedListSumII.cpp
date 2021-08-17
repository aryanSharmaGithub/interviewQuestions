    int depthSum(const vector<NestedInteger>& nestedList) {
        queue<pair<NestedInteger, int>> Q;
        // initialize
        for (auto ni : nestedList) {
            Q.push({ni, 1});
        }
        // level order bfs
        int sum = 0;
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            if (cur.first.isInteger()) {
                sum += cur.first.getInteger() * cur.second;
            } else {
                // add subtree to st
                for (auto next : cur.first.getList()) {
                    Q.push({next, cur.second + 1});
                }
            }
        }
        return sum;
    }