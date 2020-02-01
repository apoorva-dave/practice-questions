class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        stack <int> st;
        int top_ele;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else if(ops[i]=="D")
            {
                top_ele = st.top();
                st.push(top_ele*2);
            }
            else if(ops[i]=="+")
            {
                if(!st.empty())
                {
                    top_ele = st.top();
                    st.pop();
                    int el2 = st.top();
                    st.push(top_ele);
                    st.push(top_ele+el2);
                }
            }
            else
            {
                st.push(stoi(ops[i]));
            }
        }
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};