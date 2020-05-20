class StockSpanner {
public:
    vector <pair<int,int>> v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        int i = v.size()-1;
        
            while(i>=0 && price >= v[i].first) //75
            {
                cout<<v[i].first<<" "<<price<<endl;
                span += v[i].second; //4
                i -= v[i].second;
            }
        
        v.push_back(make_pair(price,span)); //100,1 80,1 60,1 70,2 60,1 75,4
        return span; //1
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */