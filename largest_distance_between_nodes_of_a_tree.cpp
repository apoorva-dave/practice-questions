#include<bits/stdc++.h>
using namespace std;
pair <int,int> bfs(int x, unordered_map <int, vector <int>> mp,int n)
{
    vector <int> dist(n,-1); //initialize dist from node x to all nodes = -1
    queue <int> q;
    q.push(x);
    dist[x] = 0; //distance from x to x
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v: mp[u])
        {
            //v is vertex reachable from node u
            if(dist[v]==-1)
            {
                q.push(v);   // push unvisited nodes in queue
                dist[v] = dist[u] + 1;  // increment distance of node v 
            }
        }
    }
    int max_dist = INT_MIN;
    int max_idx = 0;
    for(int i=0; i<dist.size();i++)
    {
        if(dist[i]>max_dist)
        {
            max_idx = i;
            max_dist = dist[i];
        }
    }
    return make_pair(max_idx, max_dist);
    // return make_pair(1,1);
}
int solve(vector<int> &A) {
    unordered_map <int, vector <int>> mp;
    int start;
    int n = A.size();
    for(int i=0; i<A.size();i++)
    {
        if(A[i]==-1)
        {
            start = i;
            continue;
        }
        mp[A[i]].push_back(i);
        mp[i].push_back(A[i]);
    }
    // for(int x:mp[3])
    // {
    //     cout<<x<<" ";
    // }
    pair <int,int> p1,p2;
    p1 = bfs(start,mp,n); //longest distance from root. p1 will contain that node x, maxdist
    cout<<p1.first<<" "<<p1.second<<endl;
    p2 = bfs(p1.first,mp,n); //max distance will be max distance from node x 
    cout<<p2.first<<" "<<p2.second;
    return p2.second;
    // return 1;
}
int main()
{
    vector <int> A{-1, 0, 0, 0, 3};
    int ans = solve(A);
    cout<<ans<<endl;
    return 0;
}