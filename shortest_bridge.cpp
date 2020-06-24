class Solution {
public:
    void dfs(vector<vector<int>>& A, int i, int j, vector <pair<int, int>> &r)
    {
        if(i < 0 || j < 0 || i >= A.size() || j >= A[i].size() || A[i][j]==0)
            return;
        A[i][j] = 0;
        r.push_back(make_pair(i,j));
        dfs(A, i+1, j, r);
        dfs(A, i-1, j, r);
        dfs(A, i, j-1, r);
        dfs(A, i, j+1, r);
        return;
    }
    int shortestBridge(vector<vector<int>>& A) {
        int count = 0;
        vector <pair<int, int>> x;
        vector <pair<int, int>> y;
        for(int i=0; i<A.size(); i++)
        {
            for(int j=0; j<A[i].size(); j++)
            {
                if(A[i][j] == 1)
                {
                    count++;
                    if(count == 1)
                    {
                        dfs(A, i, j, x);   
                    }
                    if(count == 2)
                    {
                        dfs(A, i, j, y);   
                    }   
                }
            }
        }
        int min_dist = INT_MAX;
        for(int i=0; i<x.size(); i++)
        {
            for(int j=0; j<y.size(); j++)
            {
                int dist = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second) - 1;
                if(dist < min_dist)
                    min_dist = dist;
            }
        }
        return min_dist;
    }
};