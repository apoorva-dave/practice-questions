class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /* 
        Kandane Algorithm is being used. CurrentSum tracks the positive contiguous
        segments of array to find max sum.
        maxSumSoFar stores the maximum sum seen so far in these positive segments.
        */
        int currentSum = 0;
        int maxSumSoFar = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            currentSum += nums[i];
            if(currentSum > maxSumSoFar)
                maxSumSoFar = currentSum;
            if(currentSum < 0)
            {
                currentSum = 0;
            }
        }
        return maxSumSoFar;
    }
};