#include <bits/stdc++.h>

using namespace std;

string intToString(long long x){
	ostringstream oss; /* sstream */
	oss << x; //hexadecimal -> oss << hex << x;
	return oss.str();
}

long long stringToInt(string &str){
	istringstream iss(str); /* sstream */
	long long ret;
	iss >> ret;
	return ret;
}

int main()
{
	return 0;
}
