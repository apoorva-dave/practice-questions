class Solution {
public:
    unordered_map<int,vector<int>> buildGraph(vector<vector<int>>& prerequisites)
    {
        unordered_map<int,vector<int>> mp;
        for(auto row:prerequisites)
        {
            mp[row[0]].push_back(row[1]);
            // cout<<row[0]<<" "<<row[1]<<endl;
        }
        return mp;
    }
    vector <int> findIndegree(int numCourses,  unordered_map<int,vector<int>> graph)
    {
        vector <int> indegree(numCourses,0);
        for(auto it = graph.begin();it!=graph.end();it++)
        {
            int el = it->first;
            for(auto j:graph[el])
                indegree[j]++;
        }
        return indegree;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //prerequisites is a list of edges 
        // if there exists a cycle in graph, tasks cannot be completed
        // detecting cycle using bfs
        // compute indegree of each node. push node with indegree 0 in queue.
        // when traversing reduce indegree of neighbouring nodes by 1. if 0 push in queue
        
        unordered_map<int,vector<int>> graph = buildGraph(prerequisites);
        vector <int> indegree = findIndegree(numCourses,graph);
        int countVisited=0;
        queue <int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int s = q.front();
            q.pop();
            for(auto t:graph[s])
            {
                indegree[t]--;
                if(indegree[t]==0)
                    q.push(t);
            }
            countVisited++;
        }
        if(countVisited==numCourses)
            return true;
        else
            return false;
    }
};