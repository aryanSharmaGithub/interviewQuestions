TreeNode *newRoot;
    void dfs(TreeNode* cur) {
		if (cur->left) {
			dfs(cur->left);
			cur->left->right = cur;
			cur->left->left = cur->right;
			cur->left = NULL;      // important
			cur->right = NULL;
		} else {
			newRoot = cur;
		}
	}
	
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        // Write your code here
    	if (!root) {
    	    return NULL;
    	}
        dfs(root);
        return newRoot;
    }