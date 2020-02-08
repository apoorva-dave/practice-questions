#include<bits/stdc++.h>
using namespace std;
int colorful(int A) {
    string res = to_string(A);
    vector <string> ans;
    map<int,int> mp;
    for(int p=1;p<=res.length();p++)
    {
        for(int i=0;i<res.length();i++)
        {
            if(res.substr(i,p).length()>=p)
                ans.push_back(res.substr(i,p));
        }
            
    }
    for(int i=0;i<ans.size();i++)
    {
        int mults =1;
        for(int j=0;j<ans[i].length();j++)
        {
            mults = mults * (ans[i][j] - '0');
        }
        mp[mults]++;
    }
    for(auto it =mp.begin();it!=mp.end();it++)
    {
        if(it->second>1)
            return 0;
    }
    return 1;
}
int main()
{
    int x = colorful(99);
    cout<<x;
    return 0;
}