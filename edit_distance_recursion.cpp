class Solution {
public:
 
    int findDistance(string word1, string word2, int m, int n)
    {
        if(m==0)
            return n;
        if(n==0)
            return m;
        if(word1[m-1]==word2[n-1])
            return findDistance(word1, word2, m-1, n-1);
        else
        {
            return 1+ min(findDistance(word1, word2, m, n-1), min(findDistance(word1, word2, m-1, n), findDistance(word1, word2, m-1, n-1)));
        }
    }
    int minDistance(string word1, string word2) {
        // source -> abcd target -> acbd   1st condition - > str1, str2, m-1, n-1
        // I abc, acb ->   abc, ac       "bd" -> str1, str2, m, n-1
        // D abc, acb ->   ab, acb       "d"   -> str1, str2, m-1, n
        // R abc, acb ->   ab, ac        "d"   -> str1, str2, m-1, n-1
        // if m==0 return n
        // if n==0 return m
        return findDistance(word1, word2, word1.length(), word2.length());
    }
};