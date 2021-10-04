https://leetcode.com/problems/remove-invalid-parentheses/submissions/
class Solution {
public:
    bool isValidString(string s) {
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(')
                count++;
            if(s[i] == ')')
                count--;
            if(count < 0)
                return false;
        }
        return count==0;
    }
    bool isParantheses(char c) {
        return (c=='(' || c==')');
    }
    vector<string> removeInvalidParentheses(string s) {
        /*
        isValid()
        isParantheses()
        ()())()
1 bracket removed    )())(), (())() ()))() ()()() ...
2 brackets removed    ())(), )))(),  ...
once level knows i.e how many braces to remove no need to go down into more levels
        */
        vector <string> res;
        if(s.empty()) {
            return res;
        }
        queue <string> q;
        q.push(s);
        bool level = false;
        set <string> visited;
        visited.insert(s);
        while(!q.empty()) {
            string x = q.front();
            q.pop();
            if(isValidString(x)) {
                res.push_back(x);
                level = true;
            }
            if(level)
                continue;
            for(int i=0; i<x.length(); i++) {
                if(!isParantheses(x[i]))
                    continue;
                string temp = x.substr(0,i) + x.substr(i+1);
                if(visited.find(temp) == visited.end()) {
                    q.push(temp);
                    visited.insert(temp);
                }
            }
        }
        return res;
    }
};