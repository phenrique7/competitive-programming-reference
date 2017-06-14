#include <bits/stdc++.h>

long long fastexp(long long base, long long eexp, long long mod){
   if(eexp == 0LL) return 1;
   if(eexp == 1LL) return base;    
   long long res = fastexp(base, eexp / 2, mod);   
   if(eexp & 1LL){
      return (((res * res) % mod) * base) % mod;
   }
   else{
		return (res * res) % mod;
   }
}

int main()
{
	printf("%lld\n", fastexp(2, 10));

	return 0;
}