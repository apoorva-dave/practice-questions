class BrowserHistory {
public:
    vector <string> sites;
    int current;
    BrowserHistory(string homepage) {
        sites.push_back(homepage);
        current = 0;
    }
    
    void visit(string url) {
        if(sites.size() > 0) {
            auto it = sites.begin() + current+1;
            sites.erase(it, sites.end());
            }
        sites.push_back(url);
        current = sites.size()-1;
    }
    
    string back(int steps) {
        if(current-steps > sites.size()-1) {
            current = 0;
        }
        else {
            current = current - steps;
        }
        return sites[current];
    }
    
    string forward(int steps) {
        if(current + steps > sites.size()-1) {
            current = sites.size()-1;
        }
        else {
            current = current + steps;
        }
        return sites[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */