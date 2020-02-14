vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector <int> res;
    stack <TreeNode* > st;
    TreeNode* current = A;
    if(A==NULL)
        return res;
    st.push(A);
    while (!st.empty()) {
        TreeNode* node= st.top();  
        res.push_back(node->val);
        st.pop();
        if(node->left)
            st.push(node->left);
        if(node->right)
            st.push(node->right);
    }
    reverse(res.begin(),res.end());
    return res;
}