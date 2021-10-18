// https://leetcode.com/problems/word-break-ii/
class Solution {
public:
    bool isPresent(string str, vector <string> wordDict) {
    for(int i=0; i<wordDict.size(); i++) {
        if(wordDict[i].compare(str) == 0)
            return true;
    }
        return false;
    }
    
    void wordBreakUtil(string s, int n, vector<string> wordDict, string res, vector <string> &result) {
        for(int i=1; i<=n; i++) {
            string prefix = s.substr(0, i);
            if(isPresent(prefix, wordDict)) {
                if(i == n) {
                    res = res + prefix;
                    result.push_back(res);
                    return;
                }
                wordBreakUtil(s.substr(i, n-i), n-i, wordDict, res+prefix+" ", result);
            }
        }
        return;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        wordBreakUtil(s, s.size(), wordDict, "", result);
        return result;
    }
};