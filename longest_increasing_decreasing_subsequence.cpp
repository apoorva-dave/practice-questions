#include<bits/stdc++.h>
using namespace std;
int longest_inc_dec_subsequence(vector <int> A) 
{
     if(A.size() < 1)
        return 0;
    int lis[A.size()];
    int lds[A.size()];
    
    for(int i=0; i<A.size(); i++)
    {
        lis[i] = 1;
        lds[i] = 1;
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
    //Longest decreasing subsequence
    for(int i=A.size()-2; i>=0; i--)
    {
        for(int j = A.size()-1; j>i; j--)
        {
            if(A[i] > A[j])
            {
                lds[i] = max(lds[i],lds[j]+1);
            }
        }
    }
    int max = lis[0] + lds[0] - 1;
    for(int i=0; i<A.size();i++)
    {
        int res = lis[i] + lds[i] - 1;
        if(res > max)
            max = res;
    }
    return max;
}
int main()
{
    vector <int> A{1,11,2,10,4,5,2,1};
	int ans = longest_inc_dec_subsequence(A);
	cout<<ans;
	return 0;
}
