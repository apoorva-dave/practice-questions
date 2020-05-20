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
    int count = 0;
    int ans;
    void find_inorder(TreeNode* root, int k)
    {
        if(root==NULL)
            return;
        
        if(root->left)
            find_inorder(root->left, k);

        cout<<root->val<<" "<<count<<endl;
        count++;
        if(count == k)
        {
            cout<<root->val<<endl;
            ans = root->val;
        }
        find_inorder(root->right,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return -1;
        find_inorder(root,k);
        return ans;
    }
};