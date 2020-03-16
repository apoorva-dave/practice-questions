class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        if(nums.size() < 1)
            return 0;
        for(auto it = nums.begin()+1; it!= nums.end(); it++)
        {
            if(*it == *(it-1))
            {
                count++;
                 if(count > 2)
                 {
                     nums.erase(it);
                     it--;
                 }
            }
            else
                count = 1;
        }
        return nums.size();
    }
};