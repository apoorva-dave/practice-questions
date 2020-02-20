/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
     if(node == NULL)
            return NULL;
        
        queue <UndirectedGraphNode* > q;
        unordered_map <UndirectedGraphNode*, bool> visited;
        unordered_map <int, UndirectedGraphNode*> mp;
        q.push(node);
        UndirectedGraphNode* newgraph = new UndirectedGraphNode(node->label);
        mp[newgraph->label] = newgraph;
        UndirectedGraphNode* curr = newgraph;
        visited[node] = true;
        while(!q.empty())
        {
            UndirectedGraphNode* temp = q.front();
            curr = mp[temp->label];
            q.pop();
            for(UndirectedGraphNode* neighbor : temp->neighbors)
            {
                if(visited.find(neighbor) == visited.end())
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    UndirectedGraphNode* t = new UndirectedGraphNode(neighbor->label);
                    (curr->neighbors).push_back(t);
                    mp[t->label] = t;
                }
                else {
                    (curr->neighbors).push_back(mp[neighbor->label]);
                }
            }
        }
        return newgraph;

}
