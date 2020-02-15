bool findPath(TreeNode* A, int k, vector <int> &path)
{
    if(A==NULL)
        return false;
    else
    {
        path.push_back(A->val);
        if(A->val == k)
            return true;
        if((A->left && findPath(A->left,k,path)) ||  (A->right && findPath(A->right,k,path)))
            return true;
        else
        {
            path.pop_back();
            return false;
        }
    }
}
int Solution::lca(TreeNode* A, int B, int C) {
    vector <int> path1;
    vector <int> path2;
    bool r1 = findPath(A,B,path1);
    if(!r1)
        return -1;
    bool r2 = findPath(A,C,path2);
    if(!r2)
        return -1;
    int i;
    for(i=0;i<path1.size() && i<path2.size();i++)
    {
        if(path1[i]!=path2[i])
            break;
    }
    return path1[i-1];
}