class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i;
        int len = nums.size();
        int start = 0, end = len-1;
        
        int res = binarysearch(nums,start,end,target);
        return res;
    }
    int binarysearch(vector<int> nums, int start, int end, int target)
    {
        int mid;
        mid = (start+end)/2;
        while(start<=end)
        {
            
            if(target == nums[mid])
                return mid;
            // mid element in second section of rotated array
            if(nums[mid] < nums[start])
            {
                if(target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            // element in first section of rotated array
            else if(nums[mid] > nums[end])
            {
                if(target < nums[mid] && target >= nums[start])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            // array not rotated at all
            else
            {
                if(target > nums[mid])
                    start = mid+1;
                else
                    end = mid -1;
            }
            mid = (start+end)/2;
        }
        return -1;
    }
   
};


// below solution is not O(logn)
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int i;
//         int len = nums.size();
//         int start = 0, end = len-1;
        
//         int res = binarysearch(nums,start,end,target);
//         return res;
//     }
//     int binarysearch(vector<int> nums, int start, int end, int target)
//     {
//         int mid;
//         if(nums.size()>1)
//             mid = findpivot(nums);
//         else
//             mid=0;
//         while(start<=end)
//         {
//             if(nums[mid] == target)
//                 return mid;
//             if(mid+1 <nums.size() && nums[mid+1] <= target && target <= nums[end])
//             {
//                     start = mid+1;
//             }
//             else if(mid-1 >= 0 && nums[mid-1] >= target && target >= nums[start])
//             {
//                     end = mid-1;
//             }
//             else
//             {
//                 start++;
//                 end--;
//             }
//             mid = (start+end)/2;
//         }
//         return -1;
//     }
//     int findpivot(vector <int> nums)
//     {
//         int i;
//         for(i=0;i<nums.size()-1;i++)
//         {
//             if(nums[i+1]>nums[i])
//                 continue;
//             else
//                 break;
//         }
//         return i;
//     }
// };