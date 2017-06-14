#include <bits/stdc++.h>

using namespace std;

const int N = 40005;
const int K = 16; // Quantidade maxima de arestas do vertice mais longe ate a raiz -> 2^K arestas, (1 << K) < n

struct X{
   int v, c;
};

vector<X> adj[N];
int pai[N][K], distancia[N][K], prof[N], nn;

X no(int v, int c){
	X novo; novo.v = v; novo.c = c; return novo;
}

void monta(int v, int p, int pro, int d){
	prof[v] = pro;
	pai[v][0] = p;
	distancia[v][0] = d;
	for(int i = 1; i < K; i++){
		pai[v][i] = pai[pai[v][i - 1]][i - 1];
		distancia[v][i] = distancia[v][i - 1] + distancia[pai[v][i - 1]][i - 1];
		/* pegar a maior(max) ou a menor(min) aresta do lca
		if(distancia[v][i - 1] == 0 || distancia[pai[v][i - 1]][i - 1] == 0){
			distancia[v][i] = distancia[v][i - 1] + distancia[pai[v][i - 1]][i - 1];
		}
		else{
			distancia[v][i] = max(distancia[v][i - 1], distancia[pai[v][i - 1]][i - 1]);
		}		
		*/
	}
	int sz = adj[v].size();
	for(int i = 0; i < sz; i++){
		if(adj[v][i].v == p) continue;
		monta(adj[v][i].v, v, pro + 1, adj[v][i].c);
	}
}

//monta pd com os pais em distancia 1, 2, 4, 8, ....
void calc(){
	prof[0] = 0;
	for(int i = 0; i < K; i++){
		pai[0][i] = distancia[0][i] = 0;
	}
	int sz = adj[0].size();
	for(int i = 0; i < sz; i++){
		monta(adj[0][i].v, 0, 1, adj[0][i].c);
	}
}

int dist(int a, int b){
   int pa = a, pb = b, d = 0;
   if(prof[pb] > prof[pa]) swap(pa, pb);
   //iguala niveis
   while(prof[pa] > prof[pb]){
   	int j = 0;
   	for(int i = 0; i < K; i++){
   		if(prof[pai[pa][i]] < prof[pb]) break;
   		j = i;
   	}
   	// pegar a maior(max) ou menor(min) aresta do lca
   	// ret = max(ret, distancia[pa][j]);
   	d += distancia[pa][j];
   	pa = pai[pa][j];
   }
	//vai subindo
	while(pa != pb){
		int j = 0;
		for(int i = 0; i < K; i++){
			if(pai[pa][i] == pai[pb][i]) break;
			j = i;
		}
   	// pegar a maior(max) ou menor(min) aresta do lca
   	// ret = max(ret, distancia[pa][j]);
   	// ret = max(ret, distancia[pb][j]);
   	d += distancia[pa][j];
   	d += distancia[pb][j];
   	pa = pai[pa][j];
   	pb = pai[pb][j];
	}
	return d; // return pb ou pa, retorna o menor ancestral
}

int main()
{
	/* input:
   	0 1
      0 7
      1 2
      1 3
      1 6
      3 4
      3 5
      7 8
      7 9
	*/

	nn = 10;
	for(int i = 0; i < nn; i++){
		adj[i].clear();
	}
	int aa, bb;
	for(int i = 0; i < 9; i++){
		scanf("%d %d", &aa, &bb);
		adj[aa].push_back(no(bb, 1));
		adj[bb].push_back(no(aa, 1));
	}
	calc();	
	printf("dist(4, 6): %d\n", dist(4, 6));
	printf("dist(2, 5): %d\n", dist(2, 5));
	printf("dist(1, 6): %d\n", dist(1, 6));
	printf("dist(0, 9): %d\n", dist(0, 9));
	printf("dist(4, 5): %d\n", dist(4, 5));
	printf("dist(7, 9): %d\n", dist(7, 9));
	printf("dist(4, 3): %d\n", dist(4, 3));
	printf("dist(0, 0): %d\n", dist(0, 0));
	printf("dist(8, 8): %d\n", dist(8, 8));
	printf("dist(4, 7): %d\n", dist(4, 7));
	printf("dist(2, 3): %d\n", dist(2, 3));
	
	return 0;
}
