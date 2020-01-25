#include<bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int numPaths[m][n];
 
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            numPaths[i][j] = 0;
        }
    }
    if(A[0][0] == 0)
        numPaths[0][0] = 1;
    else
        return 0;
    for(int i=0;i<m;i++)
    {
        if(A[i][0] == 0)
            numPaths[i][0] = 1;
        else
            break;
    }
    for(int j=0;j<n;j++)
    {
        if(A[0][j] == 0)
            numPaths[0][j] = 1;
        else
            break;
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(A[i][j] == 0)
                numPaths[i][j] = numPaths[i-1][j] + numPaths[i][j-1];
        }
    }
    return numPaths[m-1][n-1];
}

int main()
{
    vector<vector <int>> A{ {0, 0, 0}, 
                      {0, 1, 0}, 
                      {0, 0, 0} }; 
	int ans = uniquePathsWithObstacles(A);
	cout<<ans;
	return 0;
}