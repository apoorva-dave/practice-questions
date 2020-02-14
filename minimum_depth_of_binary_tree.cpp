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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        else
        {
            int ldepth = minDepth(root->left);
            int rdepth = minDepth(root->right);
            if(ldepth<rdepth)
            {
                if(ldepth!=0)
                    return ldepth+1;
                else
                    return rdepth+1;
            }
            else
            {
                if(rdepth!=0)
                    return rdepth+1;   
                else
                    return ldepth+1;
            }
        }
    }
};