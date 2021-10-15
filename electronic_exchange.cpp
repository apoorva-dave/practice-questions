#include<bits/stdc++.h>
using namespace std;

/*
You work in an electronic exchange. Throughout the day, you receive ticks (trading data) which consists of 
product name and its traded volume of stocks. Eg: {name: vodafone, volume: 20}. What data structure will you 
maintain if:
* You have to tell top k products traded by volume at end of day.
* You have to tell top k products traded by volume throughout the day.
*/

struct ticks {
	string productName;
	int volume;
	ticks(string p, int v) {
		productName = p;
		volume = v;
	}
};


struct compare {
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
	    return p1.second < p2.second;
    }
};

void getTopKProducts(vector<ticks>v, int k) {
	priority_queue <pair<string, int>, vector<pair<string, int>>, compare> pq;
	for(int i=0; i<v.size(); i++) {
		pq.push(make_pair(v[i].productName, v[i].volume));
	}
	while(k!=0) {
		if(!pq.empty()) {
			pair<string, int> p = pq.top();
			pq.pop();
			k--;
			cout<<p.first<< " " << p.second <<endl;
		}
	}
}

void createProductMap(vector<ticks> v, unordered_map<string, int> &mp) {
	for(int i=0; i<v.size(); i++) {
		mp[v[i].productName] += v[i].volume;
	}
}

void getTotalTopK(unordered_map<string, int> mp, int k) {
	priority_queue <pair<string, int>, vector<pair<string, int>>, compare> pq;
	for(auto m: mp) {
		pq.push(make_pair(m.first, m.second));
	}
	while(k!=0) {
		if(!pq.empty()) {
			pair<string, int> p = pq.top();
			pq.pop();
			k--;
			cout<<p.first<< " " << p.second <<endl;
		}
	}
}


int main() {
	
	// at end of day
	ticks t1 = ticks("Vodafone", 20);
	ticks t2 = ticks("Reliance", 10);
	ticks t3 = ticks("Sky", 30);

	vector <ticks> v;
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);
	int k = 3;
    cout<<"Top k products traded by volume at end of day" <<endl;
	getTopKProducts(v,k);

	// throughtout the day
	ticks t4 = ticks("Vodafone", 10);
	ticks t5 = ticks("Vodafone", 10);
	ticks t6 = ticks("Sky", 50);

	v.push_back(t4);
	v.push_back(t5);
	v.push_back(t6);
	unordered_map <string, int> mp;
	createProductMap(v, mp);
    cout<<"Top k products traded by volume throughout the day"<<endl;
	getTotalTopK(mp, k);
	return 0;
}