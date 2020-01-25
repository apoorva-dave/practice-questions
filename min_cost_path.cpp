#include<bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int> > &A) {
   
    int m = A.size();    
    int n = A[0].size();
    int cost[m][n];
    cost[0][0] = A[0][0];
    // cout<<cost[0][0];
    for(int i=1;i<m;i++)
    {
        cost[i][0] = A[i][0] + cost[i-1][0];
    }
    for(int j=1;j<n;j++)
    {
        cost[0][j] = A[0][j] + cost[0][j-1];
    }
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            cost[i][j] = A[i][j] + min(cost[i-1][j],cost[i][j-1]);
        }
    }
    return cost[m-1][n-1];
}
int main()
{
    vector<vector <int>> A{ {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 
	int ans = minPathSum(A);
	cout<<ans;
	return 0;
}