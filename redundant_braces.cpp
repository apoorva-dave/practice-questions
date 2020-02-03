int Solution::braces(string A) {
    stack <char> st;
    bool flag;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]==')')
        {
            if(!st.empty())
            {
                char top_ele = st.top();
                st.pop();
                flag = true;
                while(top_ele != '(')
                {
                    if(top_ele == '+' || top_ele == '-' ||  top_ele == '*' || top_ele == '/')
                        flag = false;
                    top_ele = st.top();
                    st.pop();
                }
            }
            if(flag)
                return true;
        }
        else
        {
            st.push(A[i]);
        }
    }
    return false;
}