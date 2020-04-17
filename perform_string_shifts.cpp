class Solution {
public:
    void left_shift(string &s, int num)
    {
        int k = 0;
        while(k<abs(num))
        {
            char temp = s[0];
            s.erase(0,1);
            s = s + temp;
            k++;
        }
    }
    void right_shift(string &s, int num)
    {
        int k = 0;
        while(k<num)
        {
            char temp = s[s.length()-1];
            s.erase(s.length()-1,1);
            s = temp + s;
            k++;
        }
    }
    string stringShift(string s, vector<vector<int>>& shift) {
        // 0 left shift, 1 right shift [direction, amount]
        // [[0,1],[1,2]]
        int count_shift = 0;
        for(int i=0; i<shift.size(); i++)
        {
            if(shift[i][0] == 0)
            {
                if(shift[i][1] != 0)
                count_shift = count_shift - (shift[i][0] + shift[i][1]);
            }
            if(shift[i][0] == 1)
                 count_shift = count_shift + (shift[i][0] * shift[i][1]);
        }
        if(count_shift == 0)
            return s;
        else if(count_shift < 0)
        {
            // left_shift count_shift number of times
            left_shift(s,count_shift);
        }
        else
        {
            right_shift(s,count_shift);
        }
        return s;
    }
};