class Solution {
public:
    void grayCodeUtil(vector <int> &res, int n, int &num)
    {
        if(n == 0)
        {
            res.push_back(num);
            return;
        }
        // ignore the bit. 
        grayCodeUtil(res, n - 1, num); 

        // invert the bit. 
        num = num ^ (1 << (n - 1)); 
        grayCodeUtil(res, n - 1, num); 
            
    }
    vector<int> grayCode(int n) {
        vector <int> res;
        int num = 0;
        grayCodeUtil(res,n,num);
        return res;
    }
};