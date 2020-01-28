#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int> > &A) {
    //extra array cannot be used
    //so to find median, we want a number which is greater than r*c/2 numbers of matrix
    int min = INT_MAX, max = INT_MIN;
    int rows = A.size();
    int cols = A[0].size();
    for(int i=0;i<rows;i++)
    {
        if(A[i][0]<min)
            min = A[i][0];
    }
    for(int i=0;i<rows;i++)
    {
        if(A[i][cols-1] > max)
            max = A[i][cols-1];
    }
    //do binary search with min and max. find upper bound of mid for each row
    // to find the number of elements less than mid
    int desired = (rows*cols + 1)/2;
    
    int mid_val;
    while(min<max)
    {
        mid_val = min + (max-min)/2;
        int place = 0;
        for(int i=0;i<rows;i++)
        {
            place += upper_bound(A[i].begin(),A[i].end(),mid_val) - A[i].begin();
        }
        if(place >= desired)
            max = mid_val;
        else
            min = mid_val+1;
    }
    return min;
}

int main()
{
    vector<vector <int>> A{{1,3},{5,6}};
    int ans = findMedian(A);
    cout<<ans;
    return 0;
}