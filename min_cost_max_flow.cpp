#include <bits/stdc++.h>

using namespace std;

const int N = 256;
const int inf = 1e9;

struct Flow{
	long long cost, flow;
};

struct Aresta{
	int v;
	long long cap, cst, flow;
	Aresta(){
		v = 0;
	 	cst = cap = flow = 0;
	}
	Aresta(int _v, long long _cap, long long _cst, long long _flow) :
	   v(_v), cap(_cap), cst(_cst), flow(_flow) {}
};

int fila[2][N], lbl[2][N], qf[2];
long long dist[N];
Aresta arestas[N * N * 2];
int grau[N], pai[N], adj[N][N];
int nv, s, t, e_cont;

struct MCMF{
	void inic(int n){
		nv = n + 2; s = n; t = n + 1; e_cont = 0;
		for(int i = 0; i < nv; i++){
			grau[i] = 0;
		}
	}
	void insere(int v1, int v2, int cap, int cst){
		arestas[e_cont++] = Aresta(v2, cap, cst, 0);
		arestas[e_cont++] = Aresta(v1, 0, -cst, 0);
		adj[v1][grau[v1]++] = e_cont - 2;
		adj[v2][grau[v2]++] = e_cont - 1;
	}
	void insereDoS(int v2, int cap, int cst){
		insere(s, v2, cap, cst);
	}
	void insereProT(int v1, int cap, int cst){
		insere(v1, t, cap, cst);
	}
	bool bellman(){
		for(int i = 0; i < nv; i++){
			dist[i] = inf;
			lbl[0][i] = lbl[1][i] = 0;
			pai[i] = -1;
		}
		qf[0] = 0; fila[0][qf[0]++] = s;
		pai[s] = -2; dist[s] = 0;
		for(int k = 0; k < nv; k++){
			int fila_at = k & 1;
			int fila_prox = 1 - fila_at;
			qf[fila_prox] = 0;
			for(int i = 0; i < qf[fila_at]; i++){
				int v = fila[fila_at][i];
				lbl[fila_at][v] = 0;
				for(int j = 0; j < grau[v]; j++){
					Aresta e = arestas[adj[v][j]];
					Aresta ei = arestas[adj[v][j] ^ 1];
					int w = e.v;
					long long cap = e.cap - e.flow, cst = e.cst;
					if(ei.flow) cst = -ei.cst;
					if(cap > 0 && dist[w] > dist[v] + cst){
						if(!lbl[fila_prox][w]){
							fila[fila_prox][qf[fila_prox]++] = w;
							lbl[fila_prox][w] = 1;
						}
						dist[w] = dist[v] + cst;
						pai[w] = adj[v][j];
					}
				}
			}
		}
		return pai[t] != -1;
	}
	Flow mcmf(){
		Flow f = (Flow){0, 0};
		while(bellman()){
			long long bot = inf, cst = 0;
			for(int v = t; pai[v] >= 0; v = arestas[pai[v] ^ 1].v){
				bot = min(bot, arestas[pai[v]].cap - arestas[pai[v]].flow);
			}
			for(int v = t; pai[v] >= 0; v = arestas[pai[v] ^ 1].v){
				Aresta &e = arestas[pai[v]];
				Aresta &ei = arestas[pai[v] ^ 1];
				if(ei.flow){
					cst += bot * (-ei.cst);
				}
				else{
					cst += bot * e.cst;
					e.flow += bot;
					ei.flow -= bot;
				}
			}
			f.flow += bot;
			f.cost += cst;
		}
		return f;
	}
};

int main()
{
	

	return 0;
}