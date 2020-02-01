class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack <char> s;
        stack <char> t;
        for(int i=0;i<S.length();i++)
        {
            if(!s.empty() && S[i]=='#')
            {
                s.pop();
            }
            else
            {
                if(S[i]!='#')
                    s.push(S[i]);
            }
        }
        for(int i=0;i<T.length();i++)
        {
            if(!t.empty() && T[i]=='#')
            {
                t.pop();
            }
            else
            {
                if(T[i]!='#')
                    t.push(T[i]);
            }
        }
        while(!s.empty() && !t.empty())
        {
            if(s.top()==t.top())
            {
                s.pop();
                t.pop();
                continue;   
            }
            else
                return false;
        }
        if(s.empty() && t.empty())
            return true;
        else
            return false;
    }
};