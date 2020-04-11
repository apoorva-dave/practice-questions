class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 4,3,2,7,8,2,3,1
        
        vector <int> res;
        for(int i=0; i<nums.size(); i++)
        {
            int x = abs(nums[i]);
            x = x-1;
            if(nums[x]>0)
            {
                nums[x] = nums[x]*-1;
            }
            // if(nums[i]!=0)
            // {
            //     int x = nums[i]-1;
            //     while(nums[x]!=0)
            //     {
            //         int temp = nums[x];
            //         nums[x] = 0;   
            //         x = temp-1;
            //     }   
            // }
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>0)
                res.push_back(i+1);
        }
        return res;
    }
};