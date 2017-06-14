#include <bits/stdc++.h>

using namespac estd;

const int inf = 1e6;
const int N = 105;
const int Q = 15;

int m[Q], pd[N];

int main()
{	
	int n, q; // troco e quantidade de moedas distintas

	scanf("%d %d", &n, &q);
	for(int i = 0; i < q; i++){
		scanf("%d", &m[i]);
	}
	pd[0] = 0;
	for(int i = 1; i <= n; i++){
		pd[i] = inf;
		for(int j = 0; j < 3; j++){
			if(i - m[j] >= 0){
				pd[i] = min(pd[i], pd[i - m[j]] + 1);
			}
		}		
	}
	printf("%d\n", pd[n]); // se pd[n] == inf, eh impossivel devolver o troco

	return 0;
}