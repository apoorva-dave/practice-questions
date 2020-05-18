class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char, int> mp;
        if(s1.length() == 0 && s2.length() == 0)
            return false;
        if(s1.length() == 0)
            return true;
        if(s2.length() == 0)
            return false;
        for(int i=0; i<s1.length(); i++)
        {
            mp[s1[i]]++;
        }
        // this gives us the count of each character in string1
        int start = 0;
        for(int end=0; end<s2.length(); )
        {
            char c = s2[end];
            if(mp[c] > 0)
            {
                mp[c]--;
                end++;
                if(end-start == s1.length())
                    return true;
            }
            else if(end == start)
            {
                end++;
                start++;
            }
            else
            {
                mp[s2[start]]++;
                start++;
            }
        }
        return false;
    }
};