#include <bits/stdc++.h>

using namespace std;

const int NMAX = 10000010;                      // 10^7 should be enough for most cases

bitset<NMAX> bs;
vector<int> p;                                  // vector p of primes

void crivo(long long n){                        // create list of primes in [0..n]
	long long lim = n + 1;                       // add 1 to include n
	bs.set();                                   // set all bits to 1
	bs[0] = bs[1] = 0;                          // except index 0 and 1
	for(long long i = 2; i <= lim; i++){
		if(bs[i]){
			for(long long j = i * i; j <= lim; j += i){ // cross out multiples of i starting from i * i!
				bs[j] = 0;
			}
			p.push_back((int)i);                // also add this vector containing list of primes
		}
	}
}

int main()
{
	crivo(100);
	
	if(bs[7]){
		puts("ok");
	}
	else{
		puts("nok");
	}

	return 0;
}
