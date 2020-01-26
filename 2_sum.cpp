#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) 
{
    int low = 0;
    int high = numbers.size()-1;
    int mid,sum;
    vector <int> res;
    while(low<=high)
    {
        sum = numbers[low] + numbers[high];
        if(sum == target)
        {
            res.push_back(low+1);
            res.push_back(high+1);
            break;
        }
        if(sum < target)
            low = low+1;
        else if(sum > target)
            high = high-1;
    }
    return res;
}
int main()
{
	vector <int> numbers{2,7,11,15};
	vector <int> ans = twoSum(numbers,9);
	for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	return 0;
}