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
    int findHeight(TreeNode* A)
    {
        if(A==NULL)
            return 0;
        else
        {
            int lh = findHeight(A->left);
            int rh = findHeight(A->right);
            if(lh>rh)
                return lh+1;
            else
                return rh+1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        /*
        diameter of binary tree =  longest path between nodes. it is max of
        1. diameter of left subtree
        2. diameter of right subtree
        3. longest path between leaves that goes through root
        */
        int lheight = findHeight(root->left);
        int rheight = findHeight(root->right);
        int ldiameter = diameterOfBinaryTree(root->left);
        int rdiameter = diameterOfBinaryTree(root->right);
        int diameter = std::max(max(ldiameter,rdiameter), lheight+rheight);
        return diameter;
    }
};