#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string A) {
    map<char, pair<int,int>> mp;
    int max_len = 0;
    int len = 0;
    int pos = 0;
    for(int i=0; i<A.length();)
    {
        pair <int,int> p;
        // cout<<mp[A[i]].second<<endl;
        if(mp[A[i]].second==0)
        {
            mp[A[i]].second++;
            p = make_pair(i,mp[A[i]].second);
            mp[A[i]] = p;
            len++;
            if(len > max_len)
                max_len = len;
            i++;
            // cout<<max_len<<endl;
        }
        else
        {
            // cout<<"hello";
            len =0;
            pos = (mp[A[i]].first)+1;
            i = pos;
            // cout<<pos;
            mp.clear();
        }
    }
    return max_len;
}
int main()
{
    string x = "bbbb";
    int ans = lengthOfLongestSubstring(x);
    cout<<ans;
    return 0;
}