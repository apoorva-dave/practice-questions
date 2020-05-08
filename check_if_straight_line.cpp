class Solution {
public:
    pair<int,int> findSlope(pair <int,int> p1, pair <int, int> p2)
    {
        int ydiff = p2.second - p1.second;
        int xdiff = (p2.first - p1.first);
        int g = __gcd(xdiff, ydiff); 
        xdiff /= g;
        ydiff /= g;
        pair <int, int> p;
        return make_pair(xdiff, ydiff);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        vector <pair <int, int>> v;
        for(int i=0; i<coordinates.size(); i++)
        {
            pair <int, int> p;
            p.first = coordinates[i][0];
            p.second = coordinates[i][1];
            v.push_back(p);
        }
        pair <int, int> p, prev;
        p = findSlope(v[0], v[1]);
        prev = p;
        // cout<<prev_slope;
        for(int i=1; i<v.size()-1; i++)
        {
            pair <int, int> p = findSlope(v[i], v[i+1]);
            if(p.first != prev.first || p.second != prev.second)
                return false;
        }
        return true;
    }
};