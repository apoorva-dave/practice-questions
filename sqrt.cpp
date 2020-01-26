#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) 
 {
    int low = 0, high = x;
    long int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        long int sq = mid*mid;
        if(sq == x)
            return mid;
        else if(sq > x)
            high = mid-1;
        else if(sq < x)
            low = mid+1;
    }
    return high;
}
int main()
{
	int n = 11;
	int ans = mySqrt(n);
	cout<<ans;
	return 0;
}