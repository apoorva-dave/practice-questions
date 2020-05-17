class Solution {
public:
    int findKadaneMax(vector <int> A)
    {
        int max_sum = A[0];
        int curr = A[0];
        for(int i= 1; i<A.size(); i++)
        {
            if(curr <= 0)
                curr = 0;
            
            curr += A[i];
            if(max_sum < curr)
                 max_sum = curr;
        }
        return max_sum;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        // max sum of circular subarray
        // using kadane's algo, we can get max sum in normal array. keep track of positive segments (A)
        // find min possible subarray sum (M), total sum of array (T)
        // to find M,invert sign of each element and find max using kadane
        // max possible sum of circular array = T + M
        // when all numbers are negatve, then T - M = 0, in this case max sum will be A
        // else ans = max(A, T+M)
        
        int maxNonCircular = findKadaneMax(A);
        cout<<maxNonCircular;
        int total_sum = 0;
        for(int i=0; i<A.size();i++)
        {
            total_sum += A[i];
            A[i] = -1 * A[i];
        }
        cout<<total_sum<<endl;
        
        int circularSum = total_sum + findKadaneMax(A);
        if(circularSum == 0)
            return maxNonCircular;
        return max(circularSum, maxNonCircular);
    
    }
};