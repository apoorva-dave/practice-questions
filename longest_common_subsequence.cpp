class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        int dp[len1+1][len2+1];
        for(int i=0;i<=len1; i++)
        {
            dp[i][0] = 0;
        }
        for(int i=0;i<=len2; i++)
        {
            dp[0][i] = 0;
        }
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] =  max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};