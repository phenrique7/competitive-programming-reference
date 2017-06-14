/*  Usando matriz de adjacencia  */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1005; //numero maximo de vertices
const int inf = 1e9; //nao ha perigo de overflow

int g[N][N]; //grafo
int pai[N]; //para reconstruir o caminho
int dist[N]; //distancia minima de cada vertice a arvore
bool mstSet[N];

long long prim(int ss, int nn){
	priority_queue<pii> pq;

	for(int i = 0; i < nn; i++){
		mstSet[i] = 0; dist[i] = inf; // AGMaxima -> troca por dist[i] = -1
	}
	int edges = 0;
	long long cst = 0;
	dist[ss] = 0;
	pai[ss] = -1;
	pq.push(make_pair(0, -ss));
	while(!pq.empty() && edges < nn){
		int uu = -pq.top().second;
		pq.pop();
		if(mstSet[uu]) continue;
		cst += dist[uu];
		mstSet[uu] = 1;
		edges++;
		for(int vv = 0; vv < nn; vv++){
			if(g[uu][vv] != 0){
				if(!mstSet[vv] && g[uu][vv] < dist[vv]){ //AGMaxima -> troca por g[uu][vv] > dist[vv]
					pai[vv] = uu;
					dist[vv] = g[uu][vv];
					pq.push(make_pair(-g[uu][vv], -vv));
				}
			}
		}
	}
	return cst;
}

int main()
{
	int nn, mm;

	while(scanf("%d %d", &nn, &mm), nn){
		for(int i = 0; i < nn; i++){
			for(int j = 0; j < nn; j++){
				g[i][j] = 0;
			}
		}
		for(int aa, bb, cst, i = 0; i < mm; i++){
			scanf("%d %d %d", &aa, &bb, &cst);
			g[aa][bb] = g[bb][aa] = cst;
		}
		long long ans = prim(0, nn);
		printf("%Ld\n", ans);
	}

	return 0;
}
