int Solution::trap(const vector<int> &A) {
    
    //store left max of each in left. similarly for right
    int left[A.size()-1];
    int right[A.size()-1];
    int sum = 0;
    left[0] = A[0];
    right[A.size()-1] = A[A.size()-1];
    for(int i=1;i<A.size();i++)
    {
        left[i] = max(left[i-1],A[i]);
    }
    for(int i=A.size()-2;i>=0;i--)
    {
        right[i] = max(right[i+1],A[i]);
    }
    for(int i=0; i<A.size();i++)
    {
        sum += min(left[i],right[i]) - A[i];
    }
    return sum;
    // int sum = 0;
    // for(int i=1; i<A.size()-1; i++)
    // {
    //     int left_max = A[i];
    //     for(int j=0;j<i;j++)
    //     {
    //         left_max = std::max(left_max,A[j]);
    //     }
    //     int right_max = A[i];
    //     for(int j=i+1;j<A.size();j++)
    //     {
    //         right_max = std::max(right_max,A[j]);
    //     }
    //     sum += std::min(left_max,right_max) - A[i];
    // }
    // return sum;
}