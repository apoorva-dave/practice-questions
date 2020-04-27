class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()<1)
            return 0;
        int rows = matrix.size();
        int col = matrix[0].size();
        int dp[rows+1][col+1];
        for(int i=0; i<=rows; i++)
        {
            dp[i][0] = 0;
        }
        for(int i=0; i<=col; i++)
        {
            dp[0][i] = 0;
        }
        int side = 0;
        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=col; j++)
            {
                if(matrix[i-1][j-1]=='0')
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                side = max(side, dp[i][j]);
            }
        }
        return side*side;
    }
};