#define WHITE 1
#define RED 2
#define BLUE 3
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        /*
        1,2 1,3 2,4
        1->2,3
        2->1,4
        3->1
        4->2
        */
        if(dislikes.size() == 0)
            return true;
        unordered_map <int, vector<int>> mp;
        queue <int> q;
        vector <bool> visited(N+1, false);
        vector <int> color(N+1, WHITE);
        for(int i=0; i < dislikes.size(); i++)
        {
           
            mp[dislikes[i][0]].push_back(dislikes[i][1]);
            mp[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        
        for(int i=1; i<=N; i++)
        {
            if(!visited[i])
            {
                q.push(i);
                color[i] = RED;
                
                while(!q.empty())
                {
                    int x = q.front();
                    q.pop();
                
                    if(visited[x])
                        continue;
                    //else check all neighbours of x and color them
                    visited[x] = true;
                    for(auto neigh: mp[x])
                    {
                        if(color[x] == color[neigh])
                            return false;
                        else if(color[x]==RED)
                            color[neigh] = BLUE;
                        else
                            color[neigh] = RED;

                        q.push(neigh);
                    }
                }
            }
        }
        return true;
    }
};