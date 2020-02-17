class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        // largest sum upto index n-1
        // largest sum upto index 5 + 10 -> largest sum upto 4 + 10*2
        // largest sum upto index i = 
        // largest sum upto index i-2 + (max(A[i-1],A[i])*2)
        //dp will store the largest sum
        int n = A.size();
        int dp[n];
        //fill dp[0] to dp[K-1]
         for(int i=0;i<n; i++)
            dp[i] = 0;
        dp[0] = A[0];
        int max = A[0];
        for(int i=1; i<K; i++)
        {
            max = std::max(max, A[i]);
            dp[i] = max * (i+1); // i+1 will be size of subarray
        }
       
        for(int i=K; i<n; i++)
        {
            //fill remaining values of dp
            int subArrayMax = A[i];
            for(int subArraySize=1; subArraySize<=K; subArraySize++)
            {
                subArrayMax = std::max(subArrayMax, A[i-subArraySize+1]);
                dp[i] = std::max(dp[i], dp[i-subArraySize] + subArrayMax * subArraySize);
            }
        }
        return dp[n-1];
    }
};