class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map <string, vector<int>> mp;
        for(int i=0; i<strs.size(); i++)
        {
            string x = strs[i];
            sort(x.begin(), x.end());
            mp[x].push_back(i);
        }
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            cout <<it->first<<endl;
            vector <string> curr;
            for(int i=0; i<it->second.size(); i++)
            {
                curr.push_back(strs[(it->second)[i]]);
            }
            res.push_back(curr);
        }
        return res;
    }
};