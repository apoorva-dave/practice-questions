#include<bits/stdc++.h>
using namespace std;
int canJump(vector<int> &A) {
    int farthestReachSoFar = 0;
    int n = A.size();
    for(int i = 0; i<n ; i++)
    {
        if(i > farthestReachSoFar || farthestReachSoFar >= n-1)
            break;
        farthestReachSoFar = max(farthestReachSoFar, A[i]+i);
    }
    return farthestReachSoFar >= n-1;
}
int main()
{
    vector <int> A{3,2,1,0,4};
	int ans = canJump(A);
	cout<<ans;
	return 0;
}
