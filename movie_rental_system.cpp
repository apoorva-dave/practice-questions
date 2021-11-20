class MovieRentingSystem {
public:
    /*
    shop, movie -> price
    movie -> set <pair<price, shop>>
    set<pair<int,pair<int,int>>> rented_movies; {price, shop, movie}
    */
    unordered_map <int, set<pair<int, int>>> mp;
    map <pair<int, int>, int> prices;
    set<pair<int, pair<int, int>>> rented_movies; // (1, (2,3))
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
         for(int i=0; i < entries.size(); i++) {
            int movie = entries[i][1];
            int shop = entries[i][0];
            int price = entries[i][2];
            mp[movie].insert(make_pair(price, shop));
            prices[make_pair(shop, movie)] = price; 
        } 
    }
    
    vector<int> search(int movie) {
        set<pair<int, int>> coll = mp[movie];
        int count = min(5, coll.size());
        vector <int> movies;
        for(auto itr: coll) {
            movies.push_back(itr.second);
            count--;
            if(count == 0) break;
        }
        return movies;
    }
    
    void rent(int shop, int movie) {
        int price = prices[make_pair(shop, movie)];
        mp[movie].erase(make_pair(price, shop));
        rented_movies.insert(make_pair(price, make_pair(shop,movie)));
    }
    
    void drop(int shop, int movie) {
        int price = prices[make_pair(shop, movie)];
        mp[movie].insert(make_pair(price, shop));
        rented_movies.erase(make_pair(price, make_pair(shop,movie)));
    }
    
    vector<vector<int>> report() {
        
        int count = min(5, rented_movies.size());
        vector <vector<int>> ans;
        for(auto itr: rented_movies) {
            int shop = (itr.second).first;
            int movie = (itr.second).second;
            ans.push_back({shop, movie});
            count--;
            if(count == 0) break;
        }
        return ans;
    }
    int min(int a, int b) {
        if(a<b) return a;
        else
            return b;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */