/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_sum = INT_MIN;
    int findSum(TreeNode* root)
    {
      if(root == NULL)
          return 0;
        else
        {
            int l = max(findSum(root->left), 0);
            int r = max(findSum(root->right), 0);
            int new_sum = root->val + l + r;
            max_sum = max(max_sum, new_sum);
            return root->val + max(l,r);
        }
        
    }
    int maxPathSum(TreeNode* root) {
        int sum = 0;
        if(root == NULL)
            return 0;

        findSum(root, 0);
        return max_sum;
    }
};