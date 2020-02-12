class Solution {
public:
    struct cmp
    {
      bool operator()(const pair <int,string> &left, const pair<int,string> &right) const
      {
          if(left.first < right.first)
              return true;
          else if(left.first == right.first && left.second > right.second)
              return true;
          else
              return false;
      }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        priority_queue <pair <int,string>, vector <pair <int,string>>, cmp> pq; 
        vector <string> res;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            pq.push(make_pair(itr->second,itr->first));
        }
        
        while(k!=0)
        {
            pair <int,string> p = pq.top();
            res.push_back(p.second);
            pq.pop();
            k--;
        }
        
        return res;
    }
};