class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int t = x;
        long long int num = 0;
        while(x > 0) {
            int rem = x % 10;
            x = x/10;
            num = num * 10 + rem;
        }
        if(num == t)
            return true;
        else
            return false;
    }
};