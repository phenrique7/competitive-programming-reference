/*
	A * B % C sem overflow
*/

#include <bits/stdc++.h>

using namespace std;

long long resto(long long a, long long b, long long c){
	long long x = 0, y = a % c;
	while(b > 0){
		if(b & 1){
			x = (x + y) % c;
		}
		y = (y * 2) % c;
		b /= 2;
	}
	return x % c;
}

int main()
{
	

	return 0;
}