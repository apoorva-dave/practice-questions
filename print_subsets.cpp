#include<bits/stdc++.h>
using namespace std;

void printSubsets(vector <int> arr) {
	int powerSetSize = pow(2, arr.size());
	for(int i=0; i<powerSetSize; i++) {
		for(int j=0; j<arr.size(); j++) {
			if(i & (1 << j)) {
				cout<<arr[j]<<' ';
			} 
		}
		cout<<endl;
	}
}

int main() {
	vector <int> v = {1,2,3};
	printSubsets(v);
	return 0;
}