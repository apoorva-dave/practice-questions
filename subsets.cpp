#include<bits/stdc++.h>
using namespace std;

void printSubsets(vector <int> arr) {
	vector <vector<int>> res;
	int powerSetSize = pow(2, arr.size());
	for(int i=0; i<powerSetSize; i++) {
		vector <int> curr;
		for(int j=0; j<arr.size(); j++) {
			if(i & (1<<j)) {
				curr.push_back(arr[j]);
			} 
		}
			res.push_back(curr);
	}
	for(int i=0; i<res.size(); i++) {
	    for(int j=0; j<res[i].size(); j++) {
	        cout<<res[i][j]; 
	    }
	    cout<<endl;
	}
}

int main() {
	vector <int> v = {1,2,3};
	printSubsets(v);
	return 0;
}