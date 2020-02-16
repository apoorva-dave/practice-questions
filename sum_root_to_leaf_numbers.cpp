/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int preorder(TreeNode *A,long long int sum)
{
    if(A==NULL)
        return 0;
    else
    {
        sum = (sum *10 + A->val)%1003;
        if(A->left==NULL && A->right==NULL)
            return sum;
        return (preorder(A->left,sum) + preorder(A->right,sum));
    }
}
int Solution::sumNumbers(TreeNode* A) {
    long long int s = preorder(A,0);
    return (s%1003);
}
