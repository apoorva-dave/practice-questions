vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue <pair <int, pair<int,int>> > pq; //sum, i, j
    set <pair <int, int>> s;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    pq.push(make_pair((A[0]+B[0]),make_pair(0,0)));
    s.insert(make_pair(0,0));
    vector <int> res;
    
    for(int count=0; count<A.size(); count++)
    {
        pair<int, pair<int, int> > temp = pq.top(); 
        pq.pop();
        res.push_back(temp.first);
        int i = temp.second.first;
        int j = temp.second.second;
        int sum = A[i] + B[j+1];
        pair <int, int> temp1 = make_pair(i,j+1);
        if(s.find(temp1) == s.end())
        {
            pq.push(make_pair(sum,temp1));
            s.insert(temp1);
        }
        sum = A[i+1] + B[j];
        temp1 = make_pair(i+1,j);
        if(s.find(temp1) == s.end())
        {
            pq.push(make_pair(sum,temp1));
            s.insert(temp1);
        }
    }
    return res;
}
