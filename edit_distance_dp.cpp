class Solution {
public:
    int minDistance(string word1, string word2) {
        // source = abcd target = acbd res = "d"
        // abc, acb -> m, n-1 res = "bd"
        // abc, acb -> m-1, n 
        // abc, acb -> m-1, n-1
        int m = word1.length();
        int n = word2.length();
        int dp[m+1][n+1];
        // word1[0,i] to word2[0,j]
        for(int i=0; i<=m; i++)
            dp[i][0] = i;
        for(int i=0; i<=n; i++)
            dp[0][i] = i;
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] =  1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[m][n];
    }
};