#include<bits/stdc++.h>
using namespace std;


void removeRangeElements(vector <int> v, vector<vector<int>> ranges, vector<int> &res) {
	vector <int> indices;
	indices.assign(v.size(), 0);
	for(int i=0; i<ranges.size(); i++) {
		indices[ranges[i][0]] = 1;
		indices[ranges[i][1]] = -1;
	}
	int sumplus1 = 0;
	int summinus1 = 0;
	for(int i=0; i<indices.size(); i++) {
		if(indices[i] == -1)
			summinus1++;
		if(indices[i] == 1)
			sumplus1++;
		if(sumplus1 <= summinus1) {
			res.push_back(v[i]);
		}
	}
}

int main() {
	vector <int> res;
	vector <int> v = {-8, 3, -5, 1, 51, 56, 0, -5, 29, 43, 78, 75, 32, 76, 73, 76};
	vector<vector<int>> ranges = {{5, 8}, {10, 13}, {3, 6}, {20, 25}};
	removeRangeElements(v, ranges, res);
	for(int i=0; i<res.size(); i++) {
		cout<<res[i]<<" ";
	}
}