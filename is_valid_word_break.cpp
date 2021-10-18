// Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated 
// sequence of dictionary words.

#include<bits/stdc++.h>
using namespace std;

bool isPresent(string str, vector <string> wordDict) {
    for(int i=0; i<wordDict.size(); i++) {
        if(wordDict[i].compare(str) == 0)
            return true;
    }
    return false;
}

bool wordBreak(string str, vector <string> wordDict) {
	int n = str.size();
	if(n==0) 
		return true;
	for(int i=1; i<=n; i++) {
		if(isPresent(str.substr(0, i), wordDict) && wordBreak(str.substr(i, n-i), wordDict)) {
			return true;
		}
	}
	return false;
}

int main() {
	string str = "ilike";
	vector <string> wordDict = {"i", "like", "sam", "sung"};
	cout<<wordBreak(str, wordDict);
	return 0;
}