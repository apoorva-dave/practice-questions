int findLCA(TreeNode* A, int B, int C)
{
    if(A==NULL)
        return -1;
    else
    {
        if(A->val == B || A->val == C)
            return A->val;
        int left_lca = findLCA(A->left,B,C);
        int right_lca = findLCA(A->right,B,C);
        if(left_lca != -1 && right_lca !=-1)
            return A->val;
        if(left_lca==-1)
            return right_lca;
        else
            return left_lca;
    }
}
bool find(TreeNode* A, int value)
{
    if(A==NULL)
        return NULL;
    else
    {
        if(A->val == value)
            return true;
        return (find(A->left,value) || find(A->right,value));
    }
}
int Solution::lca(TreeNode* A, int B, int C)
{
    bool r1= find(A,B);
    if(!r1)
        return -1;
    bool r2= find(A,C);
    if(!r2)
        return -1;
    int ans = findLCA(A,B,C);
    return ans;
}