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
    int maxLevelSum(TreeNode* root) {
        queue <TreeNode* > q;
        q.push(root);
        q.push(NULL);
        int sum_level = 0;
        int max_sum = INT_MIN;
        int level = 1;
        int max_level;
        while(q.size() > 1)
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr==NULL)
            {
                if(sum_level > max_sum)
                {
                    max_sum = sum_level;
                    max_level = level;
                }
                sum_level = 0;
                q.push(NULL);
                level++;
            }
            else
            {
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                sum_level += curr->val;
            }
        }
        if(sum_level > max_sum)
        {
            max_sum = sum_level;
            max_level = level;
        }
        return max_level;
    }
};