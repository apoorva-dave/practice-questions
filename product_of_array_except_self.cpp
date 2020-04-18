class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector <int> res;
        if(nums.size() < 1)
            return res;
        int n = nums.size();
        int left[n];
        int right[n];
        left[0] = 1;
        for(int i=1; i<n; i++)
        {
            left[i] = left[i-1] * nums[i-1];
        }
        right[n-1] = 1;
        for(int i=n-2; i>=0; i--)
        {
            right[i] = right[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++)
        {
            res.push_back(left[i]*right[i]);
        }
        return res;
    }
};