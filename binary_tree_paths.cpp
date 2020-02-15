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
    void binaryTreePathUtil(TreeNode* root, vector <string> &result, string res)
    {
        if(root==NULL)
        {
            return;
        }
        else if(root->left==NULL && root->right==NULL)
        {
            res += (to_string(root->val));
            result.push_back(res);
            return;
        }
        else
        {
            res += (to_string(root->val) + "->");
            binaryTreePathUtil(root->left,result,res);
            binaryTreePathUtil(root->right,result,res);
            return;
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> result;
        binaryTreePathUtil(root, result, "");
        return result;
    }
};