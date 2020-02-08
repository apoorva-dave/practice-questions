class Solution {
public:
    bool isHappy(int n) {
        long long int sum = 0;
        map <int,int> mp;
        while(n>0)
        {
            int rem = n%10;
            sum += (rem * rem);
            n = n/10;
            if(n<=0)
            {
                if(sum == 1)
                    return true;
                n = sum;
                if(mp[sum]==1)
                    break;
                mp[sum]++;
                sum = 0;
            }
        }
        
        return false;
    }
};