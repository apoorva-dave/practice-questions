class Solution {
public:
    vector<int> countBits(int num) {
        vector <int> res;
        if(num == 0)
        {
            res.push_back(0);
            return res;
        }
        else if(num == 1)
        {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        else
        {
            res.push_back(0);
            res.push_back(1);
        }
        for(int i=2; i<= num; i++)
        {
            int q = i/2;
            int r = i%2;
            int c = res[q] + res[r];
            res.push_back(c);
        }
        return res;
    }
};