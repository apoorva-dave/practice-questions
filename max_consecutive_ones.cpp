class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int countZeroes = 0;
        int maxLen = INT_MIN;
        for(int end=0; end<nums.size(); end++) { //10
            if(nums[end] == 0) {
                countZeroes++; //3
                while(countZeroes > k) {
                    if(nums[start] == 0) {
                        countZeroes--; //2
                    }
                      start++;  //4
                }
            }
            maxLen = max(maxLen, end-start+1); // 6
        }
        return maxLen;
    }
};