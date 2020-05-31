class Solution {
public:
    int findDistance(int x, int y)
    {
        return (y*y + x*x);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
       
        priority_queue <int, vector<int>, greater<int> > pq;
        unordered_map <int, vector <vector<int>> > mp;
        for(int i=0; i<points.size(); i++)
        {
            int d = findDistance(points[i][0],points[i][1]);
            pq.push(d);
            vector <int> curr;
            curr.push_back(points[i][0]);
            curr.push_back(points[i][1]);
            mp[d].push_back(curr);
        }
        vector <vector<int>> res;
        while(K>0 && !pq.empty())
        {
            int x = pq.top();
            pq.pop();
            auto it = mp.find(x);
            for(int i=0; i< mp[x].size(); i++)
            {
                vector <int> curr;
                curr.push_back(mp[x][i][0]);
                curr.push_back(mp[x][i][1]);
                res.push_back(curr);
                // cout<<mp[x][i][0]<<endl;
                K--;
            }
        }
        return res;
    }
};