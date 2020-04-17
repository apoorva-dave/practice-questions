class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 0 1 1 1 0 1 0 0
        //-1 0 1 2 1 2 1 0
        unordered_map <int,int> mp;
        int sum = 0;
        int len = 0;
        mp[0] = -1;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i]==1 ? 1 : -1;
            if(mp.find(sum)==mp.end())
            {
                mp[sum] = i; // -1, 0  0, -1   1, 2  2,3  
            }
            else
            {
                len = max(i-mp[sum], len);
            }
        }
        return len;
    }
};