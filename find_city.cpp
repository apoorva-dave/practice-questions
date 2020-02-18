class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // floyd warshall algorithm
        /* 
        computes shortest distance between any two vertex in graph
        O(V^3)
        consider each vertex as intermediate node and check shortest distance
        */
        vector <vector<int>> distance(n,vector <int> (n,100000));
        for(int i=0;i<edges.size();i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            distance[from][to] = distance[to][from] = weight;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        if(distance[i][j] > distance[i][k] + distance[k][j])
                            distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
        int city;
        int min_count = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<n;j++)
            {
                // cout<<distance[i][j]<<" ";
                if(distance[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            // cout<<count<<endl;
            if(count <= min_count)
            {
                min_count = count;
                city = i;
            }
        }
        
     return city;   
    }
};