class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector <int>> res;
        int i=0, j=0;
        while(i<A.size() && j<B.size())
        {
            vector <int> curr;
            int l1 = A[i][0];
            int h1 = A[i][1];
            int l2 = B[j][0];
            int h2 = B[j][1];
            // cout<<l1<<" "<<l2<<" "<<h1<<" "<<h2<<endl;
            if(l2 <= h1 && h1 <= h2)
            {
                cout<<l2<<" "<<h1<<endl;
                if(l1 <= l2)
                {
                    curr.push_back(l2);
                    curr.push_back(h1);    
                }
                else
                {
                    curr.push_back(l1);
                    curr.push_back(h1);
                }
                res.push_back(curr);
                i++;
            }
            else if(h1 >= h2)
            {
                cout<<l1<<" "<<h2<<endl;
                if(l1 <= h2)
                {
                    if(l1 <= l2)
                    {
                        curr.push_back(l2);
                        curr.push_back(h2);    
                    }
                    else
                    {
                        curr.push_back(l1);
                        curr.push_back(h2);
                    }
                    res.push_back(curr);
                }
                j++;
            }
            else
            {
                if(l1<=l2 && h1<=h2)
                    i++;
                else if(l2<=l1 && h2<=h1)
                    j++;
                else
                {
                    i++;
                    j++;
                }
            }
        }
        return res;
    }
};


/*
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        vector<vector<int>> v{};
        for(int i=0, j=0; i<A.size() && j<B.size();){
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            if(start<=end) v.push_back(vector<int>{start, end});
            if(A[i][1]<B[j][1]) ++i;
            else ++j;
        }
        return v;
    }
};


*/