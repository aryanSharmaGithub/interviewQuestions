    void helper(TreeNode *root, vector<int> &inOrder){
        if(!root) return;
        helper(root->left,inOrder);
        inOrder.push_back(root->val);
        helper(root->right,inOrder);
    }
    vector<int> closestKValues(TreeNode * root, double target, int k) {
                if(k == 1)  
            return {root->val};
        vector<int> inorder;
        helper(root, inorder);
        vector<int> res;
        int start = 0;
        int end = inorder.size() - 1;
        while(start + 1 < end) 
        {
            int mid = start + (end - start) / 2;
            if(inorder[mid] == target) 
            {
                res.push_back(inorder[mid]);
                k--;
                break;
            }
            else if(inorder[mid] < target)  
                start = mid;
            else    
                end = mid;
        }
        end = start + 1;
        while(k --) 
        {
            if(start >= 0 && end < inorder.size()) 
            {
                if(abs(inorder[start] - target) < abs(inorder[end] - target)) 
                {
                    res.push_back(inorder[start]);
                    start--;
                }
                else 
                {
                    res.push_back(inorder[end]);
                    end++;
                }
            }
            else if(start >= 0) 
            {
                res.push_back(inorder[start]);
                start--;
            }
            else
            {
                res.push_back(inorder[end]);
                end++;
            }
        }
        return res;
    }