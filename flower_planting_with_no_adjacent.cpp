class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
     //garden, flower
        unordered_map <int, vector<int>> adj_list;
        for(int i=0; i<paths.size();i++)
        {
            adj_list[paths[i][0]].push_back(paths[i][1]);
            adj_list[paths[i][1]].push_back(paths[i][0]);
        }
        //adj_list contains all paths from each node
        unordered_map<int,int> garden_flower;
        vector <int> res;
        for(int garden = 1; garden<=N; garden++)
        {
            //which flower to plant in garden = 1
            for(int flower=1; flower<=4; flower++)
            {
            // consider all flowers for garden 1 st no neighbouring garden has flower 1
                bool found = false;
                for(int neighbour:adj_list[garden])
                {
                    if(garden_flower[neighbour]==flower)
                    {
                        found = true; //flower 1 is present in 1 of the neighbours of garden 1
                        break;
                    }
                }
                if(!found)
                {
                    garden_flower[garden] = flower;
                    res.push_back(flower);
                    break;
                }
            }
        }
        return res;    
    }
};