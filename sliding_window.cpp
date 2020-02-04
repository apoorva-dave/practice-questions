vector<int> Solution::slidingMaximum(const vector<int> &nums, int k) {
       if (nums.size() == 0)
            return std::vector<int> {};
        if (nums.size() == 1)
            return std::vector<int> {nums[0]};
 
        std::vector<int> q;
        std::vector<int> ans;
        int i = 0;
        while (i < k) {
            if (q.empty())
                q.push_back(i);
            else {
                while (!q.empty() && nums[q[q.size() - 1]] < nums[i])
                    q.pop_back();
                q.push_back(i);
            }
            i++;
        }
        ans.push_back(nums[q[0]]);
 
        for (i = 1; i < nums.size() - k + 1; i++) {
            while (!q.empty() && q[0] < i)
                q.erase(q.begin());
           
            if (q.empty())
                q.push_back(i + k - 1);
            else {
                while (!q.empty() && nums[q[q.size() - 1]] < nums[i + k - 1])
                    q.pop_back();
                q.push_back(i + k - 1);
            }
            ans.push_back(nums[q[0]]);
        }
 
        return ans;
    // vector <int> res;
    // int i,max;
    // if(A.size()==1 && B == A.size())
    //     return A;
    // for(i=0;i<=A.size()-B;i++)
    // {
    //     int c = 0;
    //     max= INT_MIN;
    //     while(c!=B)
    //     {
    //         if(max<A[i])
    //         {
    //             max = A[i];
    //         }
    //         c++;
    //         i++;
    //     }
    //     res.push_back(max);
    //     // cerr<<i<<endl;
    //     i = i - B;
       
    // }
    
    // return res;
}
