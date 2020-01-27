#include<bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    //find first occurence
    int low = 0, high = nums.size()-1;
    int mid,first =-1,last=-1;
     vector <int> res;
    if(nums.size()<1)
    {

        res.push_back(first);
        res.push_back(last);
        return res;
    }

    while(low<=high)
    {
        mid = (low+high)/2;
        
        if(nums[mid] >= target)
            high = mid-1;
        else
            low = mid+1;
        if(nums[mid]==target)
            first = mid;
    }
    //find last occurence
    low = 0, high = nums.size()-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        
        if(nums[mid] <= target)
            low = mid+1;
        else
            high = mid-1;
        if(nums[mid]==target)
            last = mid;
    }
    // cout<<first<<endl;
    // cout<<last<<endl;

    res.push_back(first);
    res.push_back(last);
    return res;
}
int main()
{
    vector <int> A{5,7,7,8,8,10};
    vector <int> ans = searchRange(A,8);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}
