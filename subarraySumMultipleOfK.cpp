class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       //https://leetcode.com/problems/continuous-subarray-sum/description/?envType=daily-question&envId=2024-06-08
        // BRUTE FORCE
        // int sum = 0;
        // for(int i=0; i<nums.size(); i++) {
        //     sum = nums[i];
        //     for(int j=i+1; j<nums.size(); j++) {
        //         sum += nums[j];
        //         if(sum % k == 0) {
        //             return true;
        //         }
        //     }
        // }

        // PREFIX SUM + SLIDING WINDOW
        int sum = nums[0];
        
        for(int i=1; i<nums.size(); i++) {

            if (nums[i - 1] == 0 && nums[i] == 0) {
                return true;      
            }

            sum += nums[i];
            if(sum %k == 0)
                return true;
            int j = 0;
            int tempSum = sum;
            while(i-j > 1 && tempSum >=k) {
                tempSum -= nums[j];
                if(tempSum % k ==0) 
                    return true;
                j++;
            }
        }
        return false;
    }
};
