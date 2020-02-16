/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> zigzag_traversal(TreeNode* A, bool lefttoright)
{
    vector<vector<int>> res;
   if(A==NULL)
        return res;
    queue <TreeNode* > q;
    q.push(A);
    q.push(NULL);
    vector <int> current;
    while(q.size() > 1)
    {
        TreeNode* curr = q.front();
        q.pop();
        if(curr==NULL)
        {
            q.push(NULL);
            if(lefttoright)
                res.push_back(current);
            else
            {
                reverse(current.begin(),current.end());
                res.push_back(current);
            }
            current.clear();
            lefttoright = !lefttoright;
        }
        else
        {
            
            current.push_back(curr->val);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    if(lefttoright)
        res.push_back(current);
    else
    {
        reverse(current.begin(),current.end());
        res.push_back(current);
    }
    return res;
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > res;
    res = zigzag_traversal(A,true);
    return res;
}
