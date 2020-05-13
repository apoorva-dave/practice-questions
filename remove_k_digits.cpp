class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k == num.length())
            return "0";
        stack <int> st;
        st.push(num[0]-'0');
        for(int i=1; i<num.length(); i++)
        {
            while(!st.empty() && st.top() > (num[i]-'0') && k>0)
            {
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }
        while(k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }
        string res = "";
        while(!st.empty())
        {
            res = to_string(st.top()) + res;
            st.pop();
        }
        int i = 0;
        cout<<res<<endl;
        string r="";
        while(res[i]=='0')
        {
            cout<<"hello";
            // res.erase(i,1);
            i++;
        }
        if(i==res.length())
            return "0";
        r = res.substr(i);
        return r;
    }
};