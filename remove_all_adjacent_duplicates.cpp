class Solution {
public:
    string removeDuplicates(string S) {
        stack <char> st;
        st.push(S[0]);
        for(int i=1;i<S.length();i++)
        {
            if(!st.empty() && st.top() == S[i])
            {
                st.pop();
            }
            else
            {
                st.push(S[i]);
            }
        }
        string res="";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        string rev(res.rbegin(), res.rend());
        return rev;
    }
};