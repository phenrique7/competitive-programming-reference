/*
   Dado um conjunto de n números a[i] que a soma total é igual a M,
   e para algum K ≤ M, se existe um subconjunto dos números tais que
   a soma desse subconjunto dá exatamente K?
*/

#include <bits/stdc++.h>

const int N = 1005;
const int V = 100005;

int m[N], v[V];

int main()
{
	int nn, vv;
	
	while(scanf("%d %d", &vv, &nn), vv){
		for(int i = 0; i < nn; i++){
			scanf("%d", &m[i]);
		}
		for(int i = 0; i <= vv; i++){
			v[i] = 0;
		}
		v[0] = 1;
		for(int i = 0; i < nn; i++){
			for(int j = vv; j >= m[i]; j--){
				v[j] |= v[j - m[i]];
			}
		}
		printf("%s\n", v[vv] ? "sim" : "nao");
	}
	
	return 0;
}
