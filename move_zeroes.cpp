class Solution {
public:
    void swap(int &x, int &y)
    {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int n =  nums.size();
        for(int i=0; i<n-1; i++)
        {
            if(nums[i]==0)
            {
                for(int j = i+1; j<n; j++)
                {
                    if(nums[j]!=0)
                    {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};