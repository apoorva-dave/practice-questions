#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) 
{
    int low = 0;
    int high = nums.size()-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            low = mid+1;
        else if(nums[mid] > target)
            high = mid-1;
    }
    return -1;
}
int main()
{
	vector <int> numbers{-1,0,3,5,9,12};
	int ans = search(numbers,9);
    cout<<ans;
	return 0;
}