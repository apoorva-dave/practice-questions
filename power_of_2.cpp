class Solution {
public:
    bool isPowerOfTwo(int n) {
        // n = 16,  8, 4, 2, 1, 
        if(n == 0)
            return false;
        while(n != 1)
        {
            if(n % 2 != 0)
                return false;
            n = n/2;
        }
        return true;
    }
};