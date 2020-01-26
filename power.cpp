#include<bits/stdc++.h>
using namespace std;

 double myPow(double x, int n) 
 {

    if(n == 0)
        return 1;
    if(x == 1)
        return 1;
    // long long unsigned int t;
    // if(n < 0)
    // {
    //     t = abs(n);
    // }
    // else
    //     t = n;
    // cout<<t;
    double ans = 1;
    while(n > 0)
    {
        if(n % 2 == 0)
        {
            x = x * x;
            n = n/2;
        }
        else
        {
            if(n > 0)
                ans = ans * x;
            else
                ans = ans/x;
            n--;
        }
    }

        return ans;

}

int main()
{
    int x =2, n= 10;
	int ans = myPow(x,n);
	cout<<ans;
	return 0;
}