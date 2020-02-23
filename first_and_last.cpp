class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    int first =-1,last=-1;
     vector <int> res;
    if(nums.size()<1)
    {

        res.push_back(first);
        res.push_back(last);
        return res;
    }
    bool found_first = false;
    bool found_last = false;
    while(low<=high)
    {
        if(nums[low]==target)
        {
            first = low;
            found_first = true;
        }
        else
            low++;
        if(nums[high]==target)
        {
            last = high;
            found_last = true;
        }
        else
            high--;
        if(found_first && found_last)
            break;
    }
    res.push_back(first);
    res.push_back(last);
    return res;
    }
};