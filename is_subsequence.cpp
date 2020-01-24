#include<bits/stdc++.h>
using namespace std;
 bool isSubsequence(string s, string t) 
 {
    int ps = 0, pt = 0;
    for(int i = 0;i<t.length();i++)
    {
        if(s[ps]==t[pt])
        {
            ps++;
            pt++;
        }
        else
        {
            pt++;
        }
    }
    if(ps==s.length() && pt==t.length())
        return true;
    else
        return false;
}
int main()
{
    string s ="axc";
    string t = "ahbgdc";
	bool ans = isSubsequence(s,t);
	cout<<ans;
	return 0;
}
