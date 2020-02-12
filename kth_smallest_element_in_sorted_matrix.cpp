class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue <int, vector <int>, greater <int>> pq;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                pq.push(matrix[i][j]);
            }
        }

        while(k>1)
        {
            k--;
            pq.pop();
        }
        return pq.top();
    }
};