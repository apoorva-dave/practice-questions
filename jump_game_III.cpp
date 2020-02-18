class Solution {
public:
    void dfs(unordered_map <int,vector <int>> mp, vector<int> arr, vector <bool> &visited, int &start)
    {
        visited[start] = true;
        if(arr[start] == 0 && visited[arr[start]])
            return;
        for(int num:mp[start])
        {
            if(!visited[num])
                dfs(mp,arr,visited,num);
        }
    }
    bool canReach(vector<int>& arr, int start) {
        unordered_map <int,vector <int>> mp;
        int dest;
        int n = arr.size();
    
        for(int i=0;i<arr.size();i++)
        {
            if(i+arr[i]<n)
                mp[i].push_back(i+arr[i]);
            if(i-arr[i]>=0)
                mp[i].push_back(i-arr[i]);
        }
        vector <bool> visited(arr.size(),false);
        
        dfs(mp,arr,visited,start);
        for(int i=0;i<visited.size();i++)
            cout<<visited[i]<<" ";
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0 && visited[i])
                return true;
        }
        return false;
    }
};