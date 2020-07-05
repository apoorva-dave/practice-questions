// Time complexity - O(n^2)
// Space Complexity - O(1)
#include<iostream>
#include<algorithm>
using namespace std; 


int rwt(int arr[], int n) 
{ 

	int ans = 0; 
        
	for (int i = 1; i < n-1; i++) { 
		
		int left = arr[i]; 
		for (int j=0; j<i; j++) 
		left = max(left, arr[j]); 
		
		int right = arr[i]; 
		for (int j=i+1; j<n; j++) 
		right = max(right, arr[j]); 
		
		 
	ans = ans + (min(left, right) - arr[i]); 
	} 

     return ans; 
} 
 
int main() 
{ 
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	cout << rwt(arr, n); 
	
	return 0; 
} 
