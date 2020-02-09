class Solution {
public:
    int findDistance(vector <int> p1, vector <int> p2)
    {
        return (pow(p1[0]-p2[0],2) + pow(p1[1]-p2[1],2));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        
        for(int i=0; i<points.size(); i++)
        {
            unordered_map <int,int> mp;    
            for(int j=0;j<points.size();j++)
            {
                if(i!=j){
                mp[findDistance(points[i],points[j])]++;
                }
            }
        
            for(auto itr=mp.begin(); itr!=mp.end(); itr++)
            {
                res += (itr->second) * ((itr->second)-1);
            }
        }
        return res;
    }
};