#include<bits/stdc++.h>
using namespace std;

int isPossible(vector <int> C, int maxlen)
{
    //this function checks how many painters are needed to paint the mid value or maxlen 
    // time will be min if we all allot all painters to paint
    // returns number of painters needed to paint maxlen
    int sum = 0;
    int number_of_painters = 1;
    for(int i=0;i<C.size();i++)
    {
        sum += C[i];
        if(sum > maxlen)
        {
            sum = C[i];
            number_of_painters++;
        }
    }
    return number_of_painters;
}
int paint(int A, int B, vector<int> &C) {
    long long int low = INT_MIN;
    long long int high = 0;
    long long int mid;
    for(int i=0;i<C.size();i++)
    {
        if(C[i]>low)
            low = C[i];
        high += C[i];
    }
    //low is the maximum value of array C that means if each painter is allocated 1 board 
    //min time will be equal to max value of this array
    //high is the max time taken to paint boards which will be if only 1 painter 
    //paints all boards
    //binarysearch(C,low,high)
    while(low<high)
    {
        mid=(low+high)/2;
        int required_painters = isPossible(C,mid);
        // if low is 1 that means we can paint maxlen boards
        if(required_painters <= A)
            high = mid;
        else
            low = mid+1;
            
    }
    return (low*B)%10000003;
    
}

int main()
{
	vector <int> C{1,8,11,3};
    int A = 10;
    int B = 5;
	int ans = paint(A,B,C);
	cout<<ans;
	return 0;
}