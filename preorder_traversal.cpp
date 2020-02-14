void preorder(TreeNode* A, vector <int> &res)
{
    if(A!=NULL)
    {
        res.push_back(A->val);
        preorder(A->left,res);
        preorder(A->right,res);
    }
}
vector<int> Solution::preorderTraversal(TreeNode* root) {
    // vector <int> res;
    // preorder(A,res);
    // return res;
   vector<int> res;
    stack<TreeNode*> nodeStack;

    while (nodeStack.size() != 0 || root != NULL) {
        if(root == NULL) {
            root = nodeStack.top();
            nodeStack.pop();
        } else {
            res.push_back(root->val);
            if(root->right != NULL)
                nodeStack.push(root->right);
            root = root->left;
        }
    }
    return res;
}