TreeNode* createBST(vector <int> vec, int left, int right)
{
    if(left>right)
        return NULL;
    int mid = left + (right-left)/2;
    TreeNode* current = new TreeNode(vec[mid]);
    current->left = createBST(vec,left,mid-1);
    current->right = createBST(vec,mid+1,right);
    return current;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(A==NULL)
        return NULL;
    vector <int> vec;
    ListNode* temp = A;
    while(temp!=NULL)
    {
        vec.push_back(temp->val);
        temp=temp->next;
    }
    return createBST(vec,0,vec.size()-1);
}
