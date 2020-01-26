#include<bits/stdc++.h>
using namespace std;

 vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
 {
    unordered_set<int> s1(nums1.begin(),nums1.end());
    unordered_set<int> s2(nums2.begin(),nums2.end());
    unordered_set<int> :: iterator itr;
    int n1 = s1.size();
    int n2 = s2.size();
    vector <int> res;
    if(n1 < n2)
    {
        for(itr = s1.begin();itr != s1.end(); itr++)
        {
            if(s2.find(*itr) != s2.end())
                res.push_back(*itr);
        }
    }
    else
    {
        for(itr = s2.begin();itr != s2.end(); itr++)
        {
            if(s1.find(*itr) != s1.end())
                res.push_back(*itr);
        }
    }
    return res;    
}
int main()
{
	vector <int> num1{4,9,5};
    vector <int> num2{9,4,9,8,4};
	vector <int> ans = intersection(num1,num2);
	for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	return 0;
}