#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector <int> A, int target)
{
    int mid;
    int low = 0, high = A.size()-1;
    while(low<=high)
    {
        mid = (high+low)/2;
        if(A[mid] == target)
            return 1;
        else if(A[mid]<target)
            low = mid+1;
        else
            high = mid-1;
    }
    return 0;
}
int matrixSearch(vector<vector <int>> A, int target)
{
    int row = A.size();
    int col = A[0].size();
    int res = 0;
    for(int i=0;i<row;i++)
    {
        int low = A[i][0];
        int high = A[i][col-1];
        if(target>=low && target <=high)
        {
            res = binarysearch(A[i],target);
            break;
        }
            
    }
    return res;
}
int main()
{
    vector<vector <int>> A{{1,3},{5,6}};
    int ans = matrixSearch(A,4);
    cout<<ans;
    return 0;
}