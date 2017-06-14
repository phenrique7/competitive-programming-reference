#include <bits/stdc++.h>

using namespace std;

const int N = 130;
const int inf = 1e9;

int peso[N][N];
int dist[N], ja_saiu[N], foi_contraido[N];
int n, m;

void contrai(pii ultimos){
	int menor = min(ultimos.first, ultimos.second);
	int maior = max(ultimos.first, ultimos.second);
	for(int i = 0; i < n; i++){
		peso[menor][i] += peso[maior][i];
		peso[i][menor] = peso[menor][i];
		peso[i][maior] = peso[maior][i] = 0;
		peso[i][i] = 0;
	}
	foi_contraido[maior] = 1;
}
int pega_maior(){
	int id = -1;
	for(int i = 0; i < n; i++){
		if(foi_contraido[i] || ja_saiu[i]){
			continue;
		}
		if(id == -1 || dist[i] > dist[id]){
			id = i;
		}
	}
	return id;
}

int corte_fase(int k){
	pii ultimos = pii(0, 0);
	for(int i = 0; i < n; i++){
		dist[i] = 0;
		ja_saiu[i] = 0;
	}
	for(int i = 0; i < k; i++){
		int v = pega_maior();
		ja_saiu[v] = 1;
		ultimos.second = ultimos.first;
		ultimos.first = v;
		for(int j = 0; j < n; j++){
			dist[j] += peso[v][j];
		}
	}
	contrai(ultimos);
	return dist[ultimos.first];
}

int stoer_wagner(){
	if(n == 1){
		return 0;
	}
	int ans = inf;
	int nn = n;
	for(int i = 0; i < n; i++){
		foi_contraido[i] = 0;
	}
	for(int i = 0; i < n - 1; i++){
		int aux = corte_fase(nn--);
		ans = min(ans, aux);
	}
	return ans;
}

int main(){
	int tt;

	scanf("%d", &tt);
	while(tt--){
		scanf("%d %d", &n, &m);
		memset(peso, 0, sizeof(peso));
		for(int a, b, c, i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			peso[a][b] = c;
			peso[b][a] = c;
		}
		int ans = stoer_wagner();
		printf("%d\n", ans);
	}

	return 0;
}