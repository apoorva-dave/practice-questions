/*
Input: (1, "abcd"), (2, "efgh"), (4, "mnop"), (5, "qrst"), (3, "ijkl")

Write a program to output the data from the stream in realtime in order, so 1,2,3,4,5..
You cannot queue up the incoming data from the stream.
So for example if the first incoming bit of data is (1, "abcd"), and the second is (4, "mnop"), you cannot output (4, "mnop") until you get 2, 3.
*/

#include<bits/stdc++.h>
using namespace std;


struct compare {
	bool operator()(pair <int, string> p1, pair<int, string> p2) {
		return p1.first < p2.first;
	}
};

void outputStream(vector <pair<int, string>> list) {
	priority_queue <pair<int, string>, vector<pair<int, string>>, compare> pq;
	int lastElementStreamed = -1;
	while(incomingStream) {
		for(int i=0; i<list.size(); i++) {
				pq.push(list[i]);   //3, 4
		}
		while(!pq.empty()) {
			if(lastElementStreamed == -1 && pq.top().first == 1) {
				lastElementStreamed = p.first; //1
				cout<<p<<endl; 
				pq.pop(); 
			} // 4
			if(pq.top().first - lastElementStreamed == 1) {
				cout<<p<<endl; 
				pq.pop(); 
				lastElementStreamed = p.first; //2
				continue;
			}
		}
	}
}