class Solution {
public:
    void permute(vector<vector<int>> &res, vector<int> combination, vector <int> nums, int l, int r)
    {
        res.push_back(combination);
        for(int i=l;i<r;i++)
        {
            combination.push_back(nums[i]);
            permute(res,combination,nums,i+1,r);
            combination.pop_back();
        }
    
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> combination;
       
        permute(res,combination,nums,0,nums.size());
        
        return res;
    }
};