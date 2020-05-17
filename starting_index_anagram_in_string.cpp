class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map <char, int> anagram;
        
         vector <int> res;
        if(p.length()==0)
            return res;
        for(int i=0; i<p.length(); i++)
        {
            anagram[p[i]]++;
        }
        int start = 0, end = 0;
        for(int end=0 ; end<s.length();)
        {
            char c = s[end];
            if(anagram[c] > 0)
            {
                anagram[c]--;
                end++;
                if(end-start == p.length())
                {
                    res.push_back(start);
                }
            }
            else if(start == end)
            {
                start++;
                end++;
            }
            else
            {
                if(start != end)
                {
                    anagram[s[start]]++;
                    start++;    
                }
                
            }
        }
        return res;
    }
};