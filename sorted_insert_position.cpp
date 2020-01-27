#include<bits/stdc++.h>
using namespace std;
int findInsertPosition(vector <int> A, int ele)
{
    int low = 0, high = A.size()-1;
    int mid;
    if(ele == 0)
        return 0;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(A[mid] > ele)
            high = mid-1;
        if(A[mid] < ele)
            low = mid+1;
        else if(A[mid]==ele)
            return mid;
    }
    return low;
}
int main()
{
    vector <int> A{1,3,5,6};
    int ans = findInsertPosition(A,7);
    cout<<ans;
    return 0;
}