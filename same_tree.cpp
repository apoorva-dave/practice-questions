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
//     void preorder(TreeNode* x, vector <int> &y)
//     {
        
//         if(x!=NULL)
//         {
//             y.push_back(x->val);
//             preorder(x->left,y);
//             preorder(x->right,y);   
//         }
//         else
//             y.push_back(NULL);
//     }
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==nullptr || q == nullptr)
            return p==q;
        
        if(p->val != q->val)
            return false;
        
        bool i1 = isSameTree(p->left, q->left);
        bool i2 = isSameTree(p->right, q->right);
        if(!i1 || !i2){
            return false;
        }
        return true;
        // vector <int> pt, qt;
        // preorder(p,pt);
        // preorder(q,qt);
        // cout<<endl;
        // if(pt.size()!=qt.size())
        //     return false;
        // else
        // {
        //     for(int i=0;i<pt.size();i++)
        //     {
        //         if(pt[i]!=qt[i])
        //             return false;
        //     }
        // }
        // return true;
    }
};