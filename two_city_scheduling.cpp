class Solution {
public:
    static bool compare(pair<int,int> &p1, pair<int,int> &p2)
    {
        return (p1.first > p2.first);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> v;
        for(int i=0; i<costs.size(); i++) {
            int diff = abs(costs[i][1] - costs[i][0]);
            v.push_back(make_pair(diff, i));
        }
        sort(v.begin(), v.end(), compare);
        int ca = costs.size()/2;
        int cb = costs.size()/2;
        int ans = 0;
        for(int i=0; i<v.size(); i++) {
            int index = v[i].second;
            if(costs[index][0] < costs[index][1]) {
                if(ca != 0) {
                    ans += costs[index][0];
                    ca--;
                    continue;
                } else {
                    ans += costs[index][1];
                    cb--;
                    continue;
                }
            } else {
                 if(cb != 0) {
                    ans += costs[index][1];
                    cb--;
                    continue;
                } else {
                    ans += costs[index][0];
                    ca--;
                }
            }
        }
        return ans;
    }
};