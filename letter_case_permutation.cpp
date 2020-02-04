class Solution {
public:
    vector <string> res;
    char transform(char x)
    {
        if(isupper(x))
            return tolower(x);
        else
            return toupper(x);
    }
    void permute(string S, int start)
    {
        
        res.push_back(S);
        for(int i = start; i<S.length();i++)
        {
            if(S[i]>='a' && S[i] <= 'z' || S[i]>='A' && S[i] <= 'Z')
            {
                S[i] = transform(S[i]);
                permute(S,i+1);
                S[i] = transform(S[i]);
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        permute(S,0);
        return res;
    }
};