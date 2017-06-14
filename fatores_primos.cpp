#include <bits/stdc++.h>

using namespace std;

typedef map<long long, int> prime_map;

void squeeze(prime_map &M, long long &n, long long p){ for(; n % p == 0; n /= p) M[p]++; }

prime_map factor(long long n){
	prime_map M;

	if(n < 0) return factor(-n);
	if(n < 2) return M;

	squeeze(M, n, 2);
	squeeze(M, n, 3);

	long long maxP = sqrt(n) + 2;
	for(long long p = 5; p < maxP; p += 6){
		squeeze(M, n, p);
		squeeze(M, n, p + 2);
	}

	if(n > 1) M[n]++;

	return M;
}

int main()
{
	prime_map mp;

	mp = factor(600851475143);

	for(prime_map::iterator it = mp.begin(); it != mp.end(); it++){
		printf("%Ld %d\n", it->first, it->second);
	}

	return 0;
}