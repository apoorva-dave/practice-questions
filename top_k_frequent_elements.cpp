class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue <pair<int,int>> pq; //MAX HEAP
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push(make_pair(it->second, it->first)); 
            //pq sorts by first element. we are putting it->second as it contains count of each element
        }
        vector <int> res;
        while(k!=0)
        {
            pair <int,int> p = pq.top();
            res.push_back(p.second); //in pq first element is count, second element is the element itself
            pq.pop();
            k--;
        }
        return res;
    }
};