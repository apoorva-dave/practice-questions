#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/decode-string/

void getDecodedString(string s) {
	stack <string> st;
	vector <int> count;
	string ans = "";
	int num = 0;
	for(int i=0; i<s.length(); i++) {
	    if(isdigit(s[i])) {
	        num = num * 10 + s[i]-'0';
	        cout<<num<<endl;
	    }
		else if(s[i] == '[') {
			st.push(ans);
			count.push_back(num);
			num = 0;
			ans = "";
		} 
		else if(s[i] == ']' && !st.empty()) {
		  string last_str =  st.top();
		  int c = count.back();
		  count.pop_back();
		  st.pop();
		  while(c--) {
		       last_str+=ans;
		  }
		  ans = last_str;
		}
		else {
		    ans += s[i];
		}
		   
	}
	cout<<ans;
}

int main() {
	string s = "3[a]2[bc]";
	getDecodedString(s);
	return 0;
}