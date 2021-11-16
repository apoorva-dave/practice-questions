// https://leetcode.com/problems/design-authentication-manager/

class AuthenticationManager {
public:
    int lifeTime;
    unordered_map <string, int> tokens;
    
    AuthenticationManager(int timeToLive) {
        lifeTime = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(tokens.find(tokenId) != tokens.end()  &&  (tokens[tokenId] + lifeTime) > currentTime) {
            tokens[tokenId] = currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(auto it=tokens.begin(); it!=tokens.end(); it++) {
            if((it->second + lifeTime) > currentTime) {
                count++;
            }
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */