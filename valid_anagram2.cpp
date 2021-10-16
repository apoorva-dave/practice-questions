class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> mp_s;
        unordered_map<char, int> mp_t;
        for(int i=0; i<s.length();i++) {
            mp_s[s[i]]++;
        }
        for(int i=0; i<t.length();i++) {
            mp_t[t[i]]++;
        }
        for(auto it=mp_s.begin(); it!=mp_s.end(); it++) {
            if(it->second == mp_t[it->first] ) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};