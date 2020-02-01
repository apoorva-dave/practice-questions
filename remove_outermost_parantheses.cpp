class Solution {
public:
    string removeOuterParentheses(string S) {
        stack <char> st;
        string res ="";
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(')
            {
                if(st.empty())
                {
                    st.push(S[i]);
                }
                else
                {
                    st.push(S[i]);
                    res += S[i];
                }
            }
            else if(!st.empty() && S[i]==')' && st.top()=='(')
            {
                st.pop();
                if(!st.empty())
                    res += S[i];
            }
        }
        return res;
    }
};