class Solution {
  public:
    void dfs(vector<vector<int>>& rooms,vector<bool>& visited,int room, int &count)
    {
        visited[room]=true;
        count++;

        for(int i:rooms[room])
        {
            if(!visited[i])
                dfs(rooms,visited,i,count);
        }
        return;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int count=0;
        vector<bool>visited(rooms.size(),false);
        dfs(rooms,visited,0,count);
        if(count==rooms.size()) return true;
        return false;
    }
};
// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         unordered_map <int, vector <int>> mp;
//         // mp => key will be room no (0 to N) and value will be list (rooms to which keys present)
//         for(int i=0; i<rooms.size();i++)
//         {
//             for(int j=0; j<rooms[i].size(); j++)
//             {
//                 mp[i].push_back(rooms[i][j]);
//             }
//         }
//         unordered_map <int,bool> enter;
//         enter[0] = true;
//         for(int i=0; i<rooms.size(); i++)
//         {
//             if(enter[i])
//             {
//                 for(int room:mp[i])
//                 {
//                     // 0 -> 1,3 room = 1
//                     enter[room] = true;
//                 }
//             }
//         }
       
//         for(auto itr=enter.begin();itr!=enter.end();itr++)
//         {
//             // // check whether for all rooms
//             if(!itr->second)
//                 return false;
//             // cout<<itr->first<<" "<<itr->second<<endl;
//         }
//         return true;
//     }
// };