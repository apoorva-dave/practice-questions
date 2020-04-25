







class LRUCache {
public:
    list <pair<int,int>> l;
    unordered_map <int, list <pair<int,int>>::iterator> mp;
    int c;
    LRUCache(int capacity) {
       c = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        else
        {
            int ans = (*mp[key]).second;
            l.push_back(make_pair(key,ans));
            l.erase(mp[key]);
            mp.erase(key);
            mp.insert(make_pair(key,prev(l.end())));
            return ans;   
        }        
        // return 1;
    }
    
    void put(int key, int value) {
        if(l.size() < c)
        {
            if(mp.find(key)==mp.end())
            {
                l.push_back(make_pair(key,value));
                mp.insert(make_pair(key, prev(l.end())));        
            }
            else
            {
                auto it = mp[key];
                *it = make_pair(key,value);
                l.push_back(*it);
                l.erase(it);
                mp[key] = prev(l.end());
            }
        }
        else
        {
            if(mp.find(key)==mp.end())
            {
                int x = l.front().first;
                mp.erase(x);
                l.pop_front();
                l.push_back(make_pair(key,value));
                mp.insert(make_pair(key, prev(l.end())));       
            }
            else
            {
                auto it = mp[key];
                *it = make_pair(key,value);
                l.push_back(*it);
                l.erase(it);
                mp[key] = prev(l.end());
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
















