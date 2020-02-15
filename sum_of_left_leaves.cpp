/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void sumUtil(TreeNode* root, int &sum, bool isleft)
    {
        if(root==NULL)
            return;
        if(root!=NULL && root->left==NULL && root->right==NULL && isleft)
        {
            sum += root->val;
            return;
        }
        sumUtil(root->left,sum,true);
        sumUtil(root->right,sum,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root==NULL)
            return 0;
        else{
            sumUtil(root,sum,false);
            return sum;
        }
    }
};