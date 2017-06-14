/*
	calcula (b^p mod n) em O(log(p)) multiplicacoes
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long llu;

unsigned int fastexp2(llu b, llu p, llu mod){
	llu ret;
	for(ret = 1; p > 0; p = (p >> 1), b = (b * b) % mod){
		if(p & 1){
			ret = (ret * b) % mod;
		}
	}
	return (unsigned int)ret;
}

int main()
{
	

	return 0;
}