// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        unordered_map <char,int> mp;
        for(int i=0; i<J.length(); i++)
        {
            mp[J[i]]++;
        }
        for(int i=0; i<S.length(); i++)
        {
            if(mp.find(S[i]) != mp.end())
                count++;
        }
        // for(int i=0; i<S.length(); i++)
        // {
        //     //if S[i] in J
        //     size_t found = J.find(S[i]);
        //     if(found != std::string::npos)
        //     {
        //         count++;
        //     }
        // }
        return count;
    }
};