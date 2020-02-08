#include<bits/stdc++.h>
using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B) {
    
    vector <int> q;
    vector <int> res;
    //q will store the indices
    q.push_back(0);
    int start = 0;
    int end = B-1;
    int i;
    for(i=1;i<B;i++)
    {
        if(!q.empty() && A[i] > A[q.front()])
            q.insert(q.begin(),i);
        else
            q.push_back(i);
    }
    for(i=B;i<A.size();i++)
    {
            start = start+1;
            end = end+1;
            //window has moved forward. check if front in window
            cout<<"start"<<start<<" end"<<end<<endl;
            cout<<"front"<<q.front()<<endl;
            if(q.front()>=start && q.front()<=end)
            {
                cout<<"hello"<<endl;
                int el = q.front();
                res.push_back(A[el]);
                q.clear();
                q.push_back(el);
                if(A[q.front()]<=A[end])
                    q.insert(q.begin(),end);
                else
                    q.push_back(end);
            }
            else
            {
                int el = q.front();
                q.erase(q.begin());
                res.push_back(A[el]);
                q.push_back(i);
            }
            
    }
    res.push_back(A[q.front()]);
    return res;
}
int main()
{
    vector <int> A{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector <int> ans = slidingMaximum(A,2);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}