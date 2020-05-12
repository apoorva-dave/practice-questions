class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int low = 0, high = nums.size()-1;
        int mid = low + (high-low)/2;
        int left, right; // track length of number of elements on left and right side
        while(low < high)
        {
                cout<<low<<" "<<high<<endl;
            if(nums[mid+1] != nums[mid] && nums[mid-1] != nums[mid])
            {
                return nums[mid];
            }
            else if(nums[mid+1] == nums[mid])
            {
                
                left = mid-low;
                cout<<left<<endl;
                if(left%2==0)
                    low = mid+2;
                else
                    high = mid-1;
            }
            else
            {
                cout<<low<<" "<<high<<endl;
                left = mid-low-1;
                if(left%2==0)
                    low = mid + 1;
                else
                    high = mid-2;
            }
            mid = low+(high-low)/2;
        }
        return nums[low];
    //     int ans=nums[0];
    //     for(int i=1; i<nums.size(); i++)
    //     {
    //         ans = ans ^ nums[i];
    //     }
    //     return ans;
    }
};