class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];
        int runningMaxSum = nums[0];
        for(int i=1; i<nums.length; i++) {
            runningMaxSum = ((runningMaxSum + nums[i]) > nums[i]) ? runningMaxSum + nums[i] : nums[i];
            if (runningMaxSum > maxSum)
                maxSum = runningMaxSum;
        }
        return maxSum;
    }
}
