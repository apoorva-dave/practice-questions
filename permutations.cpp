
void find_permutations(vector<int> A, vector<vector<int> >& res, int l, int r) {
    
    if(l==r)
        res.push_back(A);
        
    for(int i=l; i<=r; i++)
    {
        swap(A[l],A[i]);
        find_permutations(A,res,l+1,r);
        swap(A[i],A[l]);
    }
    return;
}


vector<vector<int> > Solution::permute(vector<int> &A) {
    int l = 0;
    int r = A.size()-1; 
    vector<vector<int> > res;
    find_permutations(A,res,l,r);
    return res;
}
