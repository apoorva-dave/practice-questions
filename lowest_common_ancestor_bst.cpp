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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==NULL)
        //     return root;
        // else
        // {
        //     if(root->val == p->val || root->val == q->val)
        //         return root;
        //     else if(root->val > p->val && root->val > q->val)
        //         return lowestCommonAncestor(root->left,p,q);
        //     else if(root->val < p->val && root->val < q->val)
        //         return lowestCommonAncestor(root->right,p,q);
        //     else
        //         return root;
        // }
        while(root!=NULL)
        {
            if(root->val > p->val && root->val > q->val)
                return lowestCommonAncestor(root->left,p,q);
            else if(root->val < p->val && root->val < q->val)
                return lowestCommonAncestor(root->right,p,q);
            else
                break;     
        }
        return root;
    }
};