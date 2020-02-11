#include<bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
    
    int n = stones.size();
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i] = stones[i];
    }
    while(n>1)
    {
        sort(a,a+n);   
        a[n-2] = a[n-1]-a[n-2];
        n--;
    }
    return a[0];
}
int main()
{
    vector <int> x{2,7,4,1,8,1};
    int ans = lastStoneWeight(x);
    cout<<ans;
    return 0;
}