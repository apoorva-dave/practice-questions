class Twitter {
public:
    unordered_map <int,vector<int>> followers;
    map<int, vector<pair<int, int>>> tweets;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(tweets.find(userId) == tweets.end()) {
            vector <pair<int,int>> v;
            v.push_back(make_pair(time++, tweetId));
            tweets[userId] = v;
        } else {
            tweets[userId].push_back(make_pair(time++, tweetId));
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue <pair<int, int>> pq;
        for(auto tweet: tweets[userId]) {
            pq.push(tweet);
        }
        for(auto followee: followers[userId]) {
            for(auto tweet: tweets[followee]) {
                pq.push(tweet);
            }
        }
        vector <int> res;
        int count = 10;
        while(!pq.empty() && count>0) {
            res.push_back(pq.top().second);
            pq.pop();
            count--;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followers.find(followerId) == followers.end()) {
            vector <int> v;
            v.push_back(followeeId);
            followers[followerId] = v;
        } else {
            auto it = find(followers[followerId].begin(), followers[followerId].end(), followeeId);
            if(it==followers[followerId].end())
                followers[followerId].push_back(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        vector <int> followees = followers[followerId];
        auto it = find(followees.begin(), followees.end(), followeeId);
        if(it != followees.end())
            followees.erase(it);
        followers.erase(followerId);
        followers.insert(make_pair(followerId, followees));
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */