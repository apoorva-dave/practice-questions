#include<bits/stdc++.h>
using namespace std;
int findPivot(vector <int> A)
{
    int i;
    for(i=0;i<A.size()-1;i++)
    {
        if(A[i+1]>A[i])
            continue;
        else
            break;
    }
    return i;
}
int rotatedBinarySearch(vector <int> A, int target)
{
    int low = 0, high = A.size()-1;
    int mid = findPivot(A);
    while(low<=high)
    {
        if(target == A[mid])
            return mid;
        else if(target < A[mid])
        {
            if(target >= A[low])
                high = mid-1;
            else
                low = mid+1;            
        }
        else if(target > A[mid])
        {
            if(target <= A[high])
                low = mid+1;
            else
                high = mid-1;
        }
        mid = (low+high)/2;
    }
    return mid;
}
int main()
{
    vector <int> A{4,5,6,7,0,1,2};
    int ans = rotatedBinarySearch(A,2);
    cout<<ans;
    return 0;
}