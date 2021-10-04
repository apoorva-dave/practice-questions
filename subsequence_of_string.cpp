print subsequence of string

#include <bits/stdc++.h>
using namespace std;
void getSubsequence(string input, int n,  vector<string> &answer, int index = -1, string curr = "") {
   
    if(index == n)
    return;
    
    if(!curr.empty())
        answer.push_back(curr);
    
    for(int i=index+1; i<n; i++) {
        curr += input[i];
        getSubsequence(input, n, answer, i, curr);
        curr.erase(curr.size()-1);
    }
    return;
    
}

int main() {
	string input = "cab";
	vector <string> output;
	getSubsequence(input, input.length(), output);
	for(int i=0; i<output.size(); i++)
	cout<<output[i]<<endl;
	return 0;
}


c
ca
cab
cb
a
ab
b
