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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        else
        {
            bool ans = 0;
            int subSum = sum - (root->val);
            if(subSum==0 && root->left==NULL && root->right==NULL)
                return true;
            if(root->left)
                ans = ans || hasPathSum(root->left,subSum);
            if(root->right)
                ans = ans || hasPathSum(root->right,subSum);
            return ans;
        }
        
    }
};