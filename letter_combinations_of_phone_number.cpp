#include<bits/stdc++.h>
using namespace std;
string map_to_char(char x)
    {
        if(x == '2')
            return "abc";
        else if(x == '3')
            return "def";
        else if(x == '4')
            return "ghi";
        else if(x == '5')
            return "jkl";
        else if(x == '6')
            return "mno";
        else if(x == '7')
            return "pqrs";
        else if(x == '8')
            return "tuv";
        else if(x == '9')
            return "wxyz";
        return "";
    }
    void backtrack(vector <string> &res, char combination[], string digits, int start, int size)
    {
        // no more digits to check
        if(start==size)
        {
            res.push_back(combination);
            return;
        }
        // we have more digits to check
        else 
        {
                if(digits[start] == 0 || digits[start] == 1)
                    return;
                else
                {
                    string r = map_to_char(digits[start]);
                    for(int i=0; i<r.length(); i++)
                    {
                        combination[start] = r[i];
                        combination[start+1] = '\0';
                        backtrack(res,combination, digits, start+1,size);
                        combination[start+1] = '\0';
                    }    
                }   
         }
    }
    vector<string> letterCombinations(string digits) {
        vector <string> res;
         
        if(digits.length()!=0)
        {
            char combination[digits.length()+1]; 
            combination[digits.length()-1] ='\0';
            backtrack(res, combination,digits, 0, digits.length());
        }
        return res;
    }
int main()
{
    string num = "23";
    vector<string> ans = letterCombinations(num);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;
    return 0;
}