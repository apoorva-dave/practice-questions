class Solution {
public:
    void heapify(vector <int> &nums, int i, int n)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < n && nums[left] > nums[largest])
            largest = left;
        if(right < n && nums[right] > nums[largest])
            largest = right;
        if(largest != i)
        {
            swap(nums[largest],nums[i]);
            heapify(nums,largest,n);
        }
    }
    int pop(vector<int> &heap){
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(heap, 0,heap.size());
        return top;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int res;
        for(int i=n/2 -1; i>=0; i--)
            heapify(nums,i,n);
        for(int i = 1; i <= k; i++) res = pop(nums);
        return res;
    }
};