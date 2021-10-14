

 // } Driver Code Ends
/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;
    Node *parent
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};˜
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
       if(x->right != NULL) {
            getLeftMost(x->right);
       }
       else {
           Node* parent = x->parent;
           while(checkIfComingFromRight(parent, x)) {
               x = parent;
               parent = x->parent;
           }
            return parent;
       }
    }
    Node* getLeftMost(Node* x) {
        if(x->left == NULL) 
            return x;
        else 
            getLeftMost(x->left);
    }
    bool checkIfComingFromRight(Node* parent, Node* x) {
        if(parent->right == x) {
            return true;
        } else {
            return false;
        }
    }
    
};

Time Complexity: O(h), where h is the height of the tree. 
As in the second case(suppose skewed tree) we have to travel all the way towards the root.
Auxiliary Space: O(1). 
Due to no use of any data structure for storing values.