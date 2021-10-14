#include<bits/stdc++.h>
using namespace std;


int getMinSteps(int n) {
	queue <int> q;
	vector <bool> visited;
    visited.assign(n, false);
	q.push(1);
	visited[1] = true;
	visited[0] = true;
	int levels = 0;
	q.push(NULL);
	while(!q.empty()) {
		int x = q.front();
		int left = x*2;
		int right = x/3;
		q.pop();
		if(x == NULL) {
		    q.push(NULL);
		    levels++;
		    continue;
		}
		if(x == n){
			return levels;
		}
		else {
			if(!visited[left]) {
				q.push(left);
				visited[left] = true;
			}
			if(!visited[right]) {
				q.push(right);
				visited[right] = true;
			}
		}
	}
	return -1;

}

int main() {
	int n = 10;
	cout<<getMinSteps(n);
	return 0;
}