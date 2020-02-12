long long int dp[105];
long long int nck[105][105]; // nck[i][j] = number of ways j elements can be selected from i
long long int log_2[105];
long long int MOD = 1000000007;

int getLeft(int n)
{
    if(n==1)
        return 0;
    int h = log_2[n];
    int num_h = (1<<h); //2^h
    int last = n - ((1<<h) - 1); //number of elements in the last level
    if(last >= num_h/2)
        return (1 << h) - 1; // (2^h) - 1 
    else
        return (1 << h) - 1 - ((num_h / 2) - last); //?
}
long long int choose(int n, int k)
{
    if(n < k)
        return 0;

    if(n<=1)
        return 1;
    if(k==0)
        return 1;
    if(nck[n][k] != -1)
        return nck[n][k];
    long long int ans = choose(n-1,k-1) + choose(n-1,k);
    ans = ans % MOD;
    nck[n][k] = ans;
    return ans;
}
long long int numberOfHeaps(int n)
{
    if(n<=1)
        return 1;
    
    if(dp[n] != -1)
        return dp[n];
    int l = getLeft(n);
    long long int answer = choose(n-1,l) * numberOfHeaps(l)%MOD * numberOfHeaps(n-1-l);
    answer = answer % MOD;
    dp[n] = answer;
    return dp[n];
}
int Solution::solve(int A) {
    // A is the number of elements from which we want to create heaps
    // max number of heaps which can be created from A elements
    // 1 root, A - 1 elements left. 
    // ways to select left elements (l) - no of ways to select l elements from A-1
    // T(n) = T(A-1 l) * T(L) * T(R)
    
    for(int i=0;i<=A;i++)
        dp[i] = -1;
    
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<A;j++)
            nck[i][j] = -1;
    }
    
    int currpower = 1;
    int currlog = -1;
    // find log of all power of 2 elements
    for(int i=1; i<=A; i++)
    {
        if(currpower==i)
        {
            currlog++;
            currpower *= 2;
        }
        log_2[i] = currlog;
    }
    return (int)numberOfHeaps(A);
}
