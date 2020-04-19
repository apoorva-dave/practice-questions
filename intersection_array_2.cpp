class Solution {
public:
    void find_intersection(vector <int> &res, vector <int> x, vector <int> y)
    {
        unordered_map <int,int> m;
        for(int i=0; i<x.size(); i++)
                m[x[i]]++;  
        for(int i=0; i<y.size(); i++)
        {
            if(m.find(y[i]) != m.end() && m[y[i]] > 0)
            {
                res.push_back(y[i]);
                m[y[i]]--;
            }
        }
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector <int> res;
        int l1 = nums1.size();
        int l2 = nums2.size();
        
        if(l1 == 0 || l2 == 0)
            return res;
        if(l1 < l2)
        {
            find_intersection(res, nums1, nums2);
        }
        else
        {
            find_intersection(res, nums2, nums1);
        }
        return res;
    }
};