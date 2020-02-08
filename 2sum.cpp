#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(const vector<int> &A, int B) {
     map<int,int> mp;
    vector <int> res;
   for(int i=0; i<A.size(); i++)
    {
        if(mp.find(A[i]) == mp.end())
            mp[A[i]] = i;
		if (mp.find(B - A[i]) != mp.end() && mp[B - A[i]] != i) 
		{
            res.push_back(mp[B - A[i]]+1);
            res.push_back(i + 1);
            break;
        }
    }
    return res;
}
int main()
{
	vector <int> numbers{-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3};
	vector <int> ans = twoSum(numbers,-1);
	for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	return 0;
}