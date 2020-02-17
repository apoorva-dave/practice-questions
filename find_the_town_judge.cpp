class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map <int,int> incomingEdges;
        unordered_map <int,int> outgoingEdges;
        for(int i=0; i<trust.size(); i++)
        {
            incomingEdges[trust[i][1]]++;
            outgoingEdges[trust[i][0]]++;
        }
        for(int i=1;i<=N;i++)
        {
            if(incomingEdges[i]==N-1 && outgoingEdges[i]==0)
                return i;
        }
        return -1;
    }
};