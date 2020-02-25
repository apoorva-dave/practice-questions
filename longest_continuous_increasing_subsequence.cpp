class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int len =1, max_len = INT_MIN;
        if(n == 1)
            return 1;
        if(n < 1)
            return 0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1] > nums[i])
                len++;
            else
                len = 1;
            if(len > max_len)
                max_len = len;
        }
        return max_len;
    }
};