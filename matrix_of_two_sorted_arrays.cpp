#include<bits/stdc++.h>
using namespace std;

int findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    //we made sure that length of A is less than B. do binary search on A
    if(A.size()>B.size())return findMedianSortedArrays(B,A);
    int m = A.size();
    int n = B.size();
    

    int low = 0;
    int high = m;
    while(low<=high)
    {
        int partitionA = (low+high)/2;
        int partitionB = (m+n+1)/2 - partitionA;
        
        int maxLeftA = INT_MIN, maxLeftB = INT_MIN, minRightA = INT_MAX, minRightB = INT_MAX;
        if(partitionA != 0)
            maxLeftA = A[partitionA-1];
        if(partitionB != 0)
            maxLeftB = B[partitionB-1];
        if(partitionA != m)
            minRightA = A[partitionA];
        if(partitionB != n)
            minRightB = B[partitionB];
        
        if(maxLeftA<=minRightB && maxLeftB<=minRightA)
        {
            if((m+n)%2==0)
                return  (double)(max(maxLeftA,maxLeftB)+min(minRightA,minRightB))/2;
            else
                return (double)(max(maxLeftA,maxLeftB));
        }
        else if(maxLeftA > minRightB)
            high = partitionA-1;
        else if(maxLeftB>minRightA)
            low = partitionA+1;
    }
}
int main()
{
    vector <int> A{2,3};
    vector <int> B{1,4,5};
    int ans = findMedianSortedArrays(A,B);
    cout<<ans;
    return 0;
}