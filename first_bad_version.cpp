#include<bits/stdc++.h>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) 
{
    long long int low = 0;
    long long int high = n;
    long long int mid;
    while(low<=high)
    {
        // cout<<"low"<<low<<" high"<<high<<endl;
        mid = (low+high)/2;
        if(isBadVersion(mid))
        {
            // cout<<"bad "<<mid<<endl;
            high = mid-1;
        }
        if(!isBadVersion(mid))
        {
            // cout<<"good "<<mid<<endl;
            low = mid+1;
        }
    }
    return low;
}
int main()
{
	int n = 5;
	int ans = firstBadVersion(n);
	cout<<ans;
	return 0;
}