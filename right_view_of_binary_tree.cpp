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
    vector<int> rightSideView(TreeNode* root) {
        queue <TreeNode* > q;
        vector <int> rightView;
        TreeNode* temp;
        if(root == NULL) {
            return rightView;
        }
        q.push(root);
        q.push(NULL);
        rightView.push_back(root->val);
        while(q.size() > 1) {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                if(temp != NULL)
                   rightView.push_back(temp->val);
                q.push(NULL);
                temp = NULL;
            } 
            else {
                if(node->left!=NULL) {
                    q.push(node->left);
                    temp = node->left;
                }
                if(node->right != NULL) {
                    q.push(node->right);
                    temp = node->right;
                }
            }
        }
        return rightView;
    }
};