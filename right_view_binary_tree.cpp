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
    vector<int> rightSideView(TreeNode* root) {
   queue <TreeNode *> q;
    vector <int> res;
    if(root==NULL)
        return res;
   q.push(root);
   while(!q.empty())
   {
       int i =0;
       int size = q.size();
       while(i<size)
       {
           ++i;
            TreeNode* current = q.front();
           q.pop();
            if(i==size)
                res.push_back(current->val);

           if(current->left)
            q.push(current->left);
           if(current->right)
            q.push(current->right);

       }
   }
    return res;
}
};