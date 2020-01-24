#include<bits/stdc++.h>
using namespace std;
int longest_increasing_subsequence(vector <int> A) 
{
    if(A.size() < 1)
        return 0;
    int lis[A.size()];
        
    for(int i=0; i<A.size(); i++)
    {
        lis[i] = 1;
    }
    //Longest increasing subsequence
    for(int i=1;i<A.size();i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[i] > A[j])
            {
                lis[i] = max(lis[i],lis[j]+1);
            }
        }
    }
    int max = lis[0];
    for(int i=0;i<A.size();i++)
    {
        if(lis[i]>max)
            max = lis[i];
    }
   return max;
}
int main()
{
    vector <int> A{1,11,2,10,4,5,2,1};
	int ans = longest_increasing_subsequence(A);
	cout<<ans;
	return 0;
}
