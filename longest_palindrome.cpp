class Solution {
public:
    int longestPalindrome(string s) {
        map <char,int> mp;
        for(int i=0; i<s.length();i++)
        {
            mp[s[i]]++;
        }
        int len  = 0;
        bool isFirstOddLength = true;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
           if(itr->second %2 == 0)
               len += itr->second;
            else
            {
                if (isFirstOddLength) {
                    len = len + itr->second;
                    isFirstOddLength = false;
                }
                else
                    len +=((itr->second)-1);
            }
        }
        
        return len;
    }
};