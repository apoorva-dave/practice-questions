#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int min = INT_MAX;
    int max_profit = 0;
    int n = prices.size();
    for(int i=0; i<n; i++)
    {
        if(prices[i] < min)
            min = prices[i];
        else if(prices[i] - min > max_profit)
            max_profit = prices[i] - min;
    }
    return max_profit;
}
int main()
{
	vector<int> prices{7,1,5,3,6,4};
	int profit = maxProfit(prices);
	cout<<profit;
	return 0;
}
