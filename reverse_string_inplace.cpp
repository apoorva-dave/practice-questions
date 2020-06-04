class Solution {
public:
    void swap(char &x, char &y)
    {
        char temp;
        temp = x;
        x = y;
        y = temp;
    }
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size()-1;
        while(start <= end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};