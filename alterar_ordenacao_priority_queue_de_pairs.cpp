#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> psi;

#define mp make_pair

struct compare{
	bool operator()(psi const& a, psi const& b) const{
		return a.second > b.second;
	}
};

int main()
{
	priority_queue<psi, vector<psi>, compare> pq;

	pq.push(mp("cabrear", 5));
	pq.push(mp("olavo", 9));
	pq.push(mp("zezo", 10));
	pq.push(mp("rita", 1));
	pq.push(mp("pompeu", 6));
	pq.push(mp("albani", 2));

	while(!pq.empty()){
		cout << pq.top().first << " " << pq.top().second << endl;
		pq.pop();
	}

	return 0;
}
