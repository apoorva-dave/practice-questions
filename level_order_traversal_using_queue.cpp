#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector <vector<int>> levelOrder(TreeNode *root)
{
    vector <vector<int>> res;
    if(root==NULL)
        return res;
    queue <TreeNode *> q;
    q.push(root);
    q.push(NULL);
    
    vector <int> current;

    while(q.size() > 1)
    {
        TreeNode *curr = q.front();
        q.pop();
        if(curr==NULL)
        {
            q.push(NULL);
            // for(int i=0;i<current.size();i++)
            //     cout<<current[i]<<" ";
            // cout<<endl;
            res.push_back(current);
            current.clear();
        }
        else
        {
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            // cout<<curr->val<<endl;
            current.push_back(curr->val);
        }
    }
    res.push_back(current);
    // reverse(res.begin(),res.end()); // to get reverse level order traversal
    return res;
}
int main()
{
  TreeNode* root= new TreeNode(3);
  vector<vector<int>> res;
  root->left = new TreeNode(9);
  // root->left->right = new TreeNode(12);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  res = levelOrder(root);
  for(int i =0;i< res.size();i++){
    for(int j=0;j<res[i].size();j++)
    cout<<res[i][j]<<" ";
    cout<<"\n";
  }
  return 0;
}