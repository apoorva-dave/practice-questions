class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        int dp[rows][col];
        int count = 0;
        for(int i=0; i<rows; i++)
        {
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }
        for(int j=1; j<col; j++)
        {
            dp[0][j] = matrix[0][j];
            count += dp[0][j];
        }
        for(int i=1; i<rows; i++)
        {
            for(int j=1; j<col; j++)
            {
                if(matrix[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};