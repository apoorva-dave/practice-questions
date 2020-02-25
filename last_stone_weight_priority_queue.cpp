class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    priority_queue <int> pq;
    int n = stones.size();
    for(int i=0;i<n;i++)
    {
        pq.push(stones[i]);
    }
    while(pq.size()!=1)
    {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        pq.push(y-x);
    }
    return pq.top();
    }
};