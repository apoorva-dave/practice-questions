class Solution {
public:
    int bitcounts(int x)
    {
        //finds number of bits in x
        int rem;
        int count = 0;
        while(x != 0)
        {
            rem = x%2;
            x = x/2;
            if(rem == 1)
                count++;
        }
        return count;
    }
    vector<string> readBinaryWatch(int num) {
        vector <string> ans{};
        string res;
        for(int h=0;h<=11;h++)
        {
            for(int m=0; m<=59; m++)
            {
                if(bitcounts(h)+bitcounts(m) == num)
                {
                    if(m>=0 && m <=9)
                        res = to_string(h) + ":" + "0" + to_string(m);
                    else
                        res = to_string(h) + ":" + to_string(m);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};