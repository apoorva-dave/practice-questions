/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findHeight(TreeNode* A)
{
    if(A==NULL)
        return 0;
    else
    {
        int ldepth = findHeight(A->left);
        int rdepth = findHeight(A->right);
        if(ldepth>rdepth)
            return ldepth+1;
        else
            return rdepth+1;
    }
}
int Solution::isBalanced(TreeNode* A) {
    if(A==NULL)
        return 1;
    int lheight = findHeight(A->left);
    int rheight = findHeight(A->right);
    if(abs(lheight-rheight)<=1 && isBalanced(A->left) && isBalanced(A->right))
        return 1;
    else
        return 0;
}
