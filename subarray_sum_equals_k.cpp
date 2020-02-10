class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        map <int,int> mp;
        mp[0] = 1;
        for(int i=0; i<nums.size();i++)
        {
            sum += nums[i];
            if(mp.find(sum-k)!=mp.end())
                count = count+mp[sum-k];
            mp[sum]++;
        }
        // for(int i=0; i<nums.size();i++)
        // {
        //     sum += nums[i];
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(sum == k)
        //         {
        //             count++;
        //         }
        //         sum += nums[j];
        //     }
        //     if(sum == k)
        //     {
        //         count++;
        //     } 
        //     cout<<"sum"<<sum<<endl;
        //     sum = 0;
        // }
        return count;
    }
};