#include<bits/stdc++.h>
using namespace std;
int jump(vector<int> &A) {
    
    // int n =  A.size();
    // if(n < 1)
    //     return 0;
    // int dp[n];
    // dp[0] = 0;
    
    // for(int i =1; i<n ;i++)
    // {
    //     dp[i] = INT_MAX;
    //     for(int j=0; j<i; j++)
    //     {
    //         if(A[j]+j >= i && dp[j] != INT_MAX)
    //         {
    //             dp[i] = min(dp[i],dp[j]+1);
    //         }
    //     }
    // }

    // if(dp[n-1] == INT_MAX)
    //     return -1;
    // else
    //     return dp[n-1];
    int n = A.size();
    if(n <= 1)
        return 0;
    //this implies when at 0th position, max that i can reach is 0+A[0] = A[0] in 1 step
    int maxReachPos = A[0];
    int currMaxReachPos = A[0];
    int currentStep = 1;
    
    for(int i=1;i<=maxReachPos;i++)
    {
        if(i==n-1)
            return currentStep;
        currMaxReachPos = max(currMaxReachPos,A[i]+i);
        if(i == maxReachPos)
        {
            // increase number of steps as this is the max you can go in current number of steps
            if(currMaxReachPos <= i)
                return -1; // if the curr max that you can reach is less than i that means you can never reach i
            maxReachPos = currMaxReachPos;
            currentStep++;
        }
    }
    return -1;
}
int main()
{
    vector <int> A{2,3,1,1,4};
	int ans = jump(A);
	cout<<ans;
	return 0;
}
