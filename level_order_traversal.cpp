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
    
    int findHeight(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        else
        {
            int lheight = findHeight(root->left);
            int rheight = findHeight(root->right);
            if(lheight > rheight)
                return lheight+1;
            else
                return rheight+1;
        }
    }
    void levelOrderTraversal(TreeNode *root, int level, vector<int> &curr)
    {
        if(root==NULL)
            return;
        else
        {
            if(level==0)
                curr.push_back(root->val);
            else
            {
                levelOrderTraversal(root->left,level-1,curr);
                levelOrderTraversal(root->right,level-1,curr);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = findHeight(root);
        vector<vector<int>> res;
        for(int i=0;i<h;i++)
        {
            vector <int> curr;
            levelOrderTraversal(root,i,curr);
            res.push_back(curr);
        }
        return res;
    }
};