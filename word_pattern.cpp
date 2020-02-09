#include<bits/stdc++.h>
using namespace std;
bool wordPattern(string pattern, string str) {
    unordered_map<string, int> done;
    unordered_map<char,string> mp; 
    vector <string> result;
    int i,j;
    string t = "";
    for(int i=0;i<str.length();i++)
    {
        if(str[i] != ' ')
        {
            t += str[i];
        }
        else
        {
            result.push_back(t);
            t = "";
        }
    }
    result.push_back(t);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl; 
    cout<<pattern.length()<<endl;
    cout<<result.size();
    if(result.size() != pattern.length())
        return false;
    for (auto i = 0; i < pattern.size(); ++ i) 
    {
        auto c = pattern[i];
        if (mp.find(c) == mp.end())
        {
            for (auto item : mp)
            {
                if (item.second == result[i]) 
                {
                    return false;
                }
            }
            mp[c] = result[i];
        }
        else 
        {
            if (mp.find(c)->second != result[i]) 
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    string p = "aaa";
    string str = "aa aa aa";
    bool ans = wordPattern(p,str);
    cout<<ans;
    return 0;
}