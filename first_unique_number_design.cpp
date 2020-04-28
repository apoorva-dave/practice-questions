class FirstUnique {
public:
    list <int> q;
    unordered_map <int, pair<int, list <int>::iterator>> mp;
    FirstUnique(vector<int>& nums) {    
        for(int i=0; i<nums.size(); i++)
        {
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        if(mp[q.front()].first == 1)
            return q.front();
        else
            return -1;
    }
    
    void add(int value) {
        if(mp.find(value)!=mp.end())
        {
            auto it = mp.find(value);
            // get iterator in queue for value and remove it from there and insert it at the end.
            if((it->second).second != q.end())
                q.erase((it->second).second);
            mp[value].second = q.end();
            mp[value].first++;
        }
        else
        {
            q.push_back(value);
            mp[value].first++;
            mp[value].second = prev(q.end());
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */