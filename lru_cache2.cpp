class LRUCache {
public:
    list <int> frames; // list of keys
    unordered_map <int, list<int> :: iterator> mp; // key and iterator pointing to key in frames list
    unordered_map<int, int> cache; // key value
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        frames.clear();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        } 
        else {
            frames.erase(mp[key]);
            mp.erase(key);
            frames.push_front(key);
            mp[key] = frames.begin();
            return cache[key];
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            frames.erase(mp[key]);
            mp.erase(key);
            frames.push_front(key);
            mp[key] = frames.begin();
            cache[key] = value;
        } 
        else {
            if(cap > 0) {
                // space is there
                frames.push_front(key);
                mp[key] = frames.begin();
                cache[key] = value;
                cap--;
            }
            else {
                mp.erase(frames.back());
                frames.pop_back();
                frames.push_front(key);
                mp[key] = frames.begin();
                cache[key] = value;
            }
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */