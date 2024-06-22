class Solution {
    public int[] searchRange(int[] nums, int target) {
        int positions[] = new int[]{-1,-1};
        if(nums.length == 0) return positions;
        positions[0] = findFirstOccurence(nums, target);
        positions[1] = findLastOccurence(nums, target);
        
        return positions;
    }

    public int findLastOccurence(int nums[], int target) {
        
        int start = 0, end = nums.length-1;
        int mid;
        int index = -1;
        while(start <= end) { 
            mid = start + (end-start)/2; 
            if(target == nums[mid]) { 
                start = mid+1;
                index = mid;
            }
            else if(target > nums[mid]) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return index;
    }

    public int findFirstOccurence(int nums[], int target) {
        
        int start = 0, end = nums.length-1;
        int mid;
        int index = -1;
        while(start <= end) { 
            mid = start + (end-start)/2; 
            if(target == nums[mid]) { 
                end = mid-1;
                index = mid;
            }
            else if(target > nums[mid]) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return index;
    }
}
