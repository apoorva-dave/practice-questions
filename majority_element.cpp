class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> mp;
        int max_count = INT_MIN;
        int ans;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > nums.size()/2)
            {
                // max_count = mp[nums[i]];
                // ans = nums[i];
                return nums[i];
            }
        }
        return -1;
    }
};