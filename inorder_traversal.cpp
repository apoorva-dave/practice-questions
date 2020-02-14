/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// void inorder(TreeNode *A, vector <int> &res)
// {
//     if(A!=NULL)
//     {
//         inorder(A->left,res);
//         res.push_back(A->val);
//         inorder(A->right,res);
//     }
// }

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector <int> res;
    // inorder(A,res);
    // return res;
    stack <TreeNode *> st;
    TreeNode* current = A;
    while(!st.empty() || current)
    {
        if(current)
        {
            st.push(current);
            current = current->left;
        }
        else
        {
            TreeNode *p = st.top();
            res.push_back(p->val);
            st.pop();
            current = p->right;
        }
    }
    return res;
}