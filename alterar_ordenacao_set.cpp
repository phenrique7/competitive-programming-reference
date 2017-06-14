#include <bits/stdc++.h>

using namespace std;

struct compare{
	bool operator()(const int &a, const int &b) const{
		return a > b;
	}
};

set<int, compare> s;
set<int, compare>::iterator it;

int main()
{    
	s.insert(1);
	s.insert(-2);
	s.insert(7);
	s.insert(-5);
	s.insert(5);
	s.insert(4);

	for(it = s.begin(); it != s.end(); it++){
		cout << *it << endl;
	}

	return 0;
}
