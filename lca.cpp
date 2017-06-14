#include <bits/stdc++.h>

using namespace std;

const int N = 100;

vector< vector<int> > g;

bool visi[N];
int pai[N];
int h[N];
long long dist[N];

void bfs(int s, int nn){
	queue<int> f;
	
	for(int i = 0; i < nn; i++){
		visi[i] = false;
	}
	h[s] = 0;
	pai[s] = -1;
	visi[s] = true;
	f.push(s);
	while(!f.empty()){
		int u = f.front();
		f.pop();
		int sz = g[u].size();
		for(int j = 0; j < sz; j++){
			int v = g[u][j];
			if(!visi[v]){
				h[v] = h[u] + 1;
				pai[v] = u;
				visi[v] = true;
				f.push(v);
			}
		}
	}
}

/*
***Arvore com peso nas arestas (se necessario)

void bfs(int s, int nn){
	queue<int> f;
	
	for(int i = 0; i < nn; i++){
		visi[i] = false;
	}
	h[s] = dist[s] = 0;
	pai[s] = -1;
	visi[s] = true;
	f.push(s);
	while(!f.empty()){
		int u = f.front();
		f.pop();
		int sz = g[u].size();
		for(int j = 0; j < sz; j++){
			int v = g[u][j].first;
			int cst = g[u][j].second;
			if(!visi[v]){
				h[v] = h[u] + 1;
				dist[v] = dist[u] + cst;
				pai[v] = u;
				visi[v] = true;
				f.push(v);
			}
		}
	}
}
*/

int lca(int u, int v){
	int hu = h[u], hv = h[v];
	int pu = u, pv = v;
	
	if(hu < hv){
		do{
			pv = pai[pv];
			hv = h[pv];
		}while(hu < hv);
	}
	else if(hu > hv){
		do{
			pu = pai[pu];
			hu = h[pu];
		}while(hu > hv);
	}
	while(pu != pv){
		pu = pai[pu];
		pv = pai[pv];
	}
	return pv;
}

int main()
{
	int nn = 10;
	g.resize(nn);
	// ARVORE DA FIGURA 9.8 DO COMPETITIVE
	g[0].push_back(1);
	g[1].push_back(0);
	
	g[0].push_back(7);
	g[7].push_back(0);
	
	g[1].push_back(2);
	g[2].push_back(1);
	
	g[1].push_back(3);
	g[3].push_back(1);
	
	g[1].push_back(6);
	g[6].push_back(1);
	
	g[3].push_back(4);
	g[4].push_back(3);
	
	g[3].push_back(5);
	g[5].push_back(3);
	
	g[7].push_back(8);
	g[8].push_back(7);
	
	g[7].push_back(9);
	g[9].push_back(7);
	
	bfs(0, nn); // pode escolher qualquer vertice para ser a raiz da arvore
	printf("lca(4, 6): %d\n", lca(4, 6));
	printf("lca(2, 5): %d\n", lca(2, 5));
	printf("lca(1, 6): %d\n", lca(4, 6));
	printf("lca(0, 9): %d\n", lca(0, 9));
	printf("lca(4, 5): %d\n", lca(4, 5));
	printf("lca(7, 9): %d\n", lca(7, 9));
	printf("lca(4, 3): %d\n", lca(4, 3));
	printf("lca(0, 0): %d\n", lca(0, 0));
	printf("lca(8, 8): %d\n", lca(8, 8));
	printf("lca(4, 7): %d\n", lca(4, 7));
	printf("lca(4, 5): %d\n", lca(4, 5));
	printf("lca(2, 3): %d\n", lca(2, 3));
	
	return 0;
}
