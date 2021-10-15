#include<bits/stdc++.h>
using namespace std;

/*
Write a function to crush candy in one dimensional board. In candy crushing games, groups of like items are removed from the board.
In this problem, any sequence of 3 or more like items should be removed and any items adjacent to that sequence should now be 
considered adjacent to each other. 
This process should be repeated as many time as possible. You should greedily remove characters from left to right.
*/

void removeChars(string s) {
	stack <char> st;
	unordered_map <char, int> mp; // can also make stack of pair of char and integer (to track count)
	for(int i=0; i<s.length(); i++) {
		if(st.empty()) {
			st.push(s[i]);	
			mp[s[i]]++;		
		}
		else {
			char x = st.top();
			if(x == s[i] && mp[x] >= 2) {
				while(!st.empty() && st.top() == s[i]) {
					st.pop();
					mp[s[i]]--;
				}
			} 
			else {
				st.push(s[i]);
				mp[s[i]]++;	
			}
		}
	}
	string res = "";
	while(!st.empty()) {
		res += st.top();
		st.pop();
	}
 	reverse(res.begin(), res.end());
	cout<< res;
}

int main() {
	string s = "aaabbbacd";
	removeChars(s);
	return 0;
}