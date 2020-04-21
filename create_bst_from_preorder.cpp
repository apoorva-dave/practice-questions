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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() < 1)
            return NULL;
        TreeNode* root = NULL;
        for(auto i: preorder)
        {
            root = build(i, root);
        }  
        return root;
    }
    TreeNode* build(int data, TreeNode* root)
    {
        if(root == NULL)
        {
            root = new TreeNode(data);
        }
        else if(data < root->val)
            root->left = build(data, root->left);
        else
            root->right = build(data, root->right);
        return root;
    }
};