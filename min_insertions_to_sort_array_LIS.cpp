class Solution{
		
	// https://practice.geeksforgeeks.org/problems/minimum-insertions-to-sort-an-array0535/1#
	public:
	int minInsertions(int arr[], int N) 
	{ 
	    int lis[N];
	    lis[0] = 1;
	    int max_len = INT_MIN;
	    if(N == 1) {
	        return 0;
	    }
	    for(int i=1; i<N; i++) {
	        lis[i] = 1;
	        for(int j=0; j<i; j++) {
	            if(arr[i] >= arr[j] && (lis[j] + 1) > lis[i]) {
	                lis[i] = lis[j] + 1;
	            }
	           max_len = max(max_len, lis[i]);
	        }
	    }
	    return N - max_len; 
	} 
};