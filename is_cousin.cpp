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
    
    int findLevel(TreeNode* root, int x, int l)
    {
        if(root == NULL)
            return 0;
        if(root->val == x)
            return l;
        int lev = findLevel(root->left, x, l+1);
        if(lev != 0)
            return lev;
        return findLevel(root->right, x, l+1);
    }
    bool isSibling(TreeNode* root, int x, int y)
    {
        if(root == NULL)
            return false;
        else if(root->left != NULL && root->right !=NULL && ((root->left->val == x && root->right->val == y) || (root->right->val == x && root->left->val == y)))
       {
           return true;
       }
        else
        {
            return (isSibling(root->left, x, y) || (isSibling(root->right, x, y)));
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
        int l1 = 0, l2 = 0;
        l1 = findLevel(root, x, l1);
        l2 = findLevel(root, y, l2);
        cout<<l1<<" "<<l2<<endl;
        if(l1 == l2)
        {
            if(!isSibling(root, x, y))
                return true;
            else
                return false;
        }
        else
            return false;
    }
};