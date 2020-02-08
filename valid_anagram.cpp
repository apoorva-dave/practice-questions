class Solution {
public:
    bool isAnagram(string s, string t) {
        map <char,int> mp_s;
        map <char,int> mp_t;
        if(s.length()!=t.length())
            return false;
        for(int i=0; i<s.length(); i++)
        {
            mp_s[s[i]]++;
        }
        for(int i=0; i<t.length(); i++)
        {
            mp_t[t[i]]++;
        }
        for(auto it=mp_s.begin();it!=mp_s.end();it++)
        {
            char x = it->first;
            if(it->second == mp_t[x])
                continue;
            else
                return false;
        }
        return true;
    }
};