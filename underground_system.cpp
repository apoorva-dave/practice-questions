class UndergroundSystem {
public:
    unordered_map <int, pair<string,int>> mp;
    unordered_map <string, pair<int,int>> stationMap;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string key = mp[id].first + "$" + stationName;
        if(stationMap.find(key) == stationMap.end()) {
            stationMap[key] = make_pair(t-mp[id].second, 1); //5,1
        } else {
            int currentTotTime = t - mp[id].second; //6
            int newTotTime = stationMap[key].first + currentTotTime; //11
            int count = stationMap[key].second; //2
            stationMap.erase(key);
            stationMap[key] = make_pair(newTotTime, count+1);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "$" + endStation;
        double avgTime = (stationMap[key].first)* 1.0/(stationMap[key].second);
        return avgTime;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */