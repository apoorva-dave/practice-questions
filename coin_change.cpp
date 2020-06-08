class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i][j] where i is the combination of coins, and j is the amount. in how many ways i can
        // get the amount from this combination of coins.
        int dp[coins.size()+1][amount+1];
        // if amount = 0 no matter what coins we have number of ways to make amount = 0 is 1
        for(int i=0; i<coins.size()+1; i++)
        {
           dp[i][0] = 1;
        }
        // for all amounts, if i do not have any coins number of ways to make amount will be 0
        for(int i=1; i<amount+1; i++)
        {
            dp[0][i] = 0;
        }
        
        /*
                0   1   2   3   4   5
        {}      1   0   0   0   0   0
        {1}     1   
        {1,2}   1
        {1,2,5} 1
        */
        // 2 options include that coin and reduce amount or do not include that coin and keep the amount as it is
        // going up in same col is do not include that coin, going in same row is include that coin
        for(int i=1; i<coins.size()+1; i++)
        {
            for(int j=1; j<amount+1; j++)
            {
                if(j-coins[i-1] >= 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];  //j-coins[i-1] means go to col where if we include coin what is total no of ways to get amount j
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[coins.size()][amount];
    }
};