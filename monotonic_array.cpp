class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        int equal = 1;
        bool is_inc = false, is_dec = false;
        for(int i=0;i<n-1;i++)
        {
            if(A[i+1] < A[i])
            {
                if(!is_inc)
                    is_dec = true;
                else
                    return false;
            }
            else if(A[i+1] > A[i])
            {
                if(!is_dec)
                    is_inc = true;
                else
                    return false;
            }
            else
                equal++;
        }
        if(is_inc && !is_dec)
            return is_inc;
        if(is_dec && !is_inc)
            return is_dec;
        if(equal == n)
            return true;
        return false;
    }
};