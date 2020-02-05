class Solution {
public:
    bool isPalindrome(string s, int low,int high)
    {
        while(low<high)
        {
            if(s[low]!=s[high])
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    
    void permute(vector<vector<string>> &res, vector <string> &curr, int start, int n, string s)
    {
        if(start>=n)
        {
            res.push_back(curr);
            return;
        }
        else
        {
            for(int i=start; i<n; i++)
            {
                if(isPalindrome(s,start,i))
                {
                    curr.push_back(s.substr(start,i-start+1));
                    permute(res,curr,i+1,n,s);
                    curr.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector <string> curr;
        int start = 0;
        int n = s.length();
        permute(res,curr,start,n,s);
        return res;
    }
};