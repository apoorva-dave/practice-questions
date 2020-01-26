#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& A)
{
    int low = 0;
    int high = A.size()-1;
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        // cout<<mid;
        if(A[mid] > A[mid-1] && A[mid] > A[mid+1] && mid+1<A.size())
        {
            // cout<<"hi";
            return mid;
        }
        else if(A[mid] < A[mid-1])
        {
            high = mid-1;
        }
        else if(A[mid] < A[mid+1])
        {
            low = mid+1;
        }
    }
    return -1;
}
int main()
{
	vector <int> numbers{0,2,1,0};
	int ans = peakIndexInMountainArray(numbers);
    cout<<ans;
	return 0;
}