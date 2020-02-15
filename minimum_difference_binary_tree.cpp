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
    // void inorder(TreeNode* root, vector <int> &res)
    // {
    //     if(root!=NULL)
    //     {
    //         inorder(root->left,res);
    //         res.push_back(root->val);
    //         inorder(root->right,res);
    //     }
    // }
    void mindiff(TreeNode* &prev, TreeNode* curr, int &ans)
    {
        if(curr==NULL)
            return;
        mindiff(prev,curr->left,ans);
        if(prev!=NULL)
            ans = std::min((curr->val-prev->val),ans);
        prev=curr;
        mindiff(prev,curr->right,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* curr=root;
        int ans = INT_MAX;
        mindiff(prev,curr,ans);
        return ans;
        // vector <int> res;
        // inorder(root,res);
        // sort(res.begin(),res.end());
        // int diff;
        // int min_diff = INT_MAX;
        // for(int i=0;i<res.size()-1;i++)
        // {
        //     diff= res[i+1] - res[i];
        //     if(min_diff>diff)
        //         min_diff=diff;
        // }
        // return min_diff;
    }
};