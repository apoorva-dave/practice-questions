void combinationSumUtil(vector<vector<int> > &res, vector <int> &curr, vector <int> A, int start, int B, int curr_sum)
    {
        if(curr_sum > B)
        {
            return;
        }
        if(curr_sum == B)
        {
            // sort(curr.begin(),curr.end());
            res.push_back(curr);
            return;
        }
        
        else
        {
            for(int i=start; i< A.size(); i++)
            {
                curr_sum += A[i];
                curr.push_back(A[i]);
                combinationSumUtil(res,curr,A,i,B,curr_sum);
                curr_sum -= A[i];
                curr.pop_back();
            }
        }
}
bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) 
{
  int i = 0;
  while (i < v1.size() && i < v2.size() && v1[i] == v2[i])
    i++;
  if (i < v1.size() && i < v2.size())
    return v2[i] > v1[i];
  else
    return (i > v2.size());
}  
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector <vector<int>> res;
    vector <int> curr;
    sort(A.begin(),A.end());
    
    combinationSumUtil(res,curr,A,0,B,0);
    sort(res.begin(), res.end(),sortcol);
    res.erase(std::unique(res.begin(), res.end()), res.end());
    return res;
}
