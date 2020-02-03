int Solution::evalRPN(vector<string> &A) {
    int ans;
    stack <int> st;
    for(int i=0;i<A.size();i++)
    {
        if(!st.empty() && A[i]=="+")
        {
            int el1 = st.top();
            st.pop();
            int el2 = st.top();
            st.pop();
            st.push(el1+el2);
        }
        else if(!st.empty() && A[i]=="-")
        {
            int el1 = st.top();
            st.pop();
            int el2 = st.top();
            st.pop();
            st.push(el2-el1);
        }
        else if(!st.empty() && A[i]=="*")
        {
            int el1 = st.top();
            st.pop();
            int el2 = st.top();
            st.pop();
            st.push(el1*el2);
        }
        else if(!st.empty() && A[i]=="/")
        {
            int el1 = st.top();
            st.pop();
            int el2 = st.top();
            st.pop();
            st.push(el2/el1);
        }
        else
        {
            st.push(stoi(A[i]));
        }
    }
    if(!st.empty())
        return st.top();
    
}
