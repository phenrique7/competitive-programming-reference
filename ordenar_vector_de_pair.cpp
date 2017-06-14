#include <bits/stdc++.h>

using namespace std;

typedef vector< pair<int,string> > vpis;
typedef pair<int,string> pis;

bool compare(const pis &left, const pis &right){
    return left.first < right.first;
}

int main()
{
	vpis myVector;

	myVector.push_back(make_pair(1, "pedro"));
	myVector.push_back(make_pair(-6, "Jv"));
	myVector.push_back(make_pair(1, "Carla"));
	myVector.push_back(make_pair(7, "Edson"));
	myVector.push_back(make_pair(10, "Tio"));
	myVector.push_back(make_pair(3, "Lorena"));
	myVector.push_back(make_pair(7, "Sergio"));
	
	stable_sort(myVector.begin(), myVector.end(), compare);

	cout << endl;
	for(vpis::iterator it = myVector.begin(); it != myVector.end(); it++)
		cout << it->first << " " << it->second << endl;

	return 0;
}

