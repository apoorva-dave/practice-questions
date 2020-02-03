vector<int> Solution::prevSmaller(vector<int> &A) {
    stack <int> st;
    //nearest smaller element on the left for each element of A
    vector <int> res;
    res.push_back(-1);
    st.push(A[0]);
    for(int i=1;i<A.size();i++)
    {
        while(!st.empty() && st.top() >= A[i])
        {
            st.pop();
        }
        if(!st.empty() && st.top() < A[i])
            res.push_back(st.top());
        else
            res.push_back(-1);
        st.push(A[i]);
    }
    return res;
}
