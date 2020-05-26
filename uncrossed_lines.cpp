class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = B.size();
        int n = A.size();
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++)
        {
            dp[i][0] = 0;
        }
        for(int i=0; i<=n; i++)
        {
            dp[0][i] = 0;
        }
        cout<<dp[0][0]<<" "<<dp[0][1]<<" "<<dp[1][0]<<endl;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(A[j-1] == B[i-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m][n];
    }
};