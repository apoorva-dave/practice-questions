class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]] = i;
            }
            else
            {
                mp[s[i]] = -1;
            }
        }
        int min_ans = INT_MAX;
        for(char x='a';x<='z';x++)
        {
            if(mp.find(x)!=mp.end() && mp[x]!=-1)
            {
                if(min_ans>mp[x])
                    min_ans=mp[x];
            }
        }
        return min_ans==INT_MAX ? -1 : min_ans;
    }
};