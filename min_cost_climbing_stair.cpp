#include<bits/stdc++.h>
using namespace std;
int minCostClimbingStairs(vector<int>& cost) {
        
    if(cost.size() == 0)
        return 0;
    if(cost.size() == 1)
        return cost[0];
    if(cost.size() == 2)
        return cost[1];
    int dp[cost.size()];
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2;i<cost.size();i++)
    {
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    return min(dp[cost.size()-1],dp[cost.size()-2]);
}

int main()
{
    vector<int> cost{10,15,20};
	int ans = minCostClimbingStairs(cost);
	cout<<ans;
	return 0;
}
