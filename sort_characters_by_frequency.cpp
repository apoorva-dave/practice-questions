class Solution {
public:
    static bool sortbyval(const pair<char,int> &p1, const pair<char,int> &p2)
    {
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        unordered_map <char, int> mp;
        for(int i=0; i<s.length(); i++)
        {
            mp[s[i]]++;
        }
        string res = "";
        vector <pair<char,int>> v;
        for(auto it=mp.begin(); it!= mp.end(); it++)
        {
            v.push_back(make_pair(it->first,it->second));
        }
        sort(v.begin(), v.end(), sortbyval); 
        /*
        t - 4      t-4
        e - 1      w-3
        r - 2      r-2
        w = 3      e-1
        */
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[i].second;j++)
                res += v[i].first;
        }
        return res;
    }
};