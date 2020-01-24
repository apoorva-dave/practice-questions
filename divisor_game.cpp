#include<bits/stdc++.h>
using namespace std;
bool divisorGame(int N) 
{
    // If you give opponent an odd number always, he loses.
    // if N is odd, only an even number can be generated and so Alice loses
    if(N % 2 == 0)
        return true;
    else
        return false;
}

int main()
{
    int n = 8;
	bool ans = divisorGame(n);
	cout<<ans;
	return 0;
}
