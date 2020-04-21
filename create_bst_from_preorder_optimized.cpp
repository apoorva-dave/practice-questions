TreeNode* bstFromPreorder(vector<int>& preorder, int parent_val = INT_MAX) {
        if(idx == preorder.size() || preorder[idx] > parent_val)
            return NULL;
        int curr_val = preorder[idx++];
        TreeNode* temp = new TreeNode(curr_val);
        temp->left = bstFromPreorder(preorder, curr_val);
        temp->right = bstFromPreorder(preorder, parent_val);
        return temp;
    }