/* Usando Lista de adjacencia */

#include <bits/stdc++.h>

using namespace std;

const int N = 1005; //numero maximo de vertices
const int inf = 1e9; //nao ha perigo de overflow

typedef pair<int, int> pii;

vector< vector<pii> > g; //grafo
int pai[N];
int dist[N]; //distancia minima de cada vertice a arvore
bool mstSet[N];

/* se necessario
struct compare{
	bool operator()(pii const& a, pii const& b) const{
		return a.second > b.second; //Menor no topo
	}
};
*/

long long prim(int ss, int nn){
	priority_queue<pii> pq;

	for(int i = 0; i < nn; i++){
		mstSet[i] = 0; dist[i] = inf;
	}
	int edges = 0;
	long long cst = 0;
	dist[ss] = 0LL;
	pai[ss] = -1;
	pq.push(make_pair(0LL, -ss));
	while(!pq.empty() && edges < nn){
		int uu = -pq.top().second;
		pq.pop();
		if(mstSet[uu]) continue;
		cst += dist[uu];
		mstSet[uu] = 1;
		edges++;
		int sz = g[uu].size();
		for(int j = 0; j < sz; j++){
			int vv = g[uu][j].first;
			int cc = g[uu][j].second;
			if(!mstSet[vv] && cc < dist[vv]){
				pai[vv] = uu;
				dist[vv] = cc;
				pq.push(make_pair(-cc, -vv));
			}
		}
	}
	return cst;
}

int main()
{
	int nn, mm;

	while(scanf("%d %d", &nn, &mm), nn){
		g.resize(nn);
		for(int aa, bb, cst, i = 0; i < mm; i++){
			scanf("%d %d %d", &aa, &bb, &cst);
			g[aa].push_back(make_pair(bb, cst));
			g[bb].push_back(make_pair(aa, cst));
		}
		long long ans = prim(0, nn);
		printf("%Ld\n", ans);
		g.clear();
	}

	return 0;
}
