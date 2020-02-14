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
    bool isMirror(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
            return true;
        if(root1 && root2 && root1->val == root2->val)
            return (isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left));
        return false;
    }
    bool isSymmetric(TreeNode* root) {
     return isMirror(root,root);
        
    }
};