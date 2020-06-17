class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector <int> v;
    unordered_map <int, int> mp;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) == mp.end())
        {
            mp[val] = v.size();
            v.push_back(val);
            return true;
        }
        else
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) != mp.end())
        {
            int temp = v.back();
            v.back() = v[mp[val]];
            v[mp[val]] = temp;
            mp[temp] = mp[val];
            mp.erase(val);
            v.pop_back();
            return true;
        }
        else
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randIndex = rand() % v.size();
        cout<<randIndex;
        return v[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */