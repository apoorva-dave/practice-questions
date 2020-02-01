class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        stack <int> st;
        vector <int> res;
        
        if(nums1.size() < 1)
            return nums1;
        if(nums2.size() < 1)
            return nums2;
        st.push(nums2[0]);
        for(int i=1;i<nums2.size();i++)
        {
            while(!st.empty() && nums2[i]>st.top())
            {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(mp[nums1[i]]!=0)
                res.push_back(mp[nums1[i]]);
            else
                res.push_back(-1);
        }
        return res;

    }
};