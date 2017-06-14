/*
Grafo DAG

0 -> 1 -> 3 -> 4
|
v         6 <- 7
2 -> 5

*/

#include <bits/stdc++.h>

using namespace std;

const int V = 8;

bool visi[V];
vector<int> ts;

vector< vector<int> > g;

void dfs2(int u){
	visi[u] = true;
	int sz = g[u].size();
	for(int j = 0; j < sz; j++){
		int v = g[u][j];
		if(!visi[v]){
			dfs2(v);
		}
	}
	ts.push_back(u);
}

int main()
{
	g.resize(8);

	g[0].push_back(1);
	g[0].push_back(2);
	g[1].push_back(2);
	g[1].push_back(3);
	g[2].push_back(3);
	g[2].push_back(5);
	g[3].push_back(4);
	g[7].push_back(6);

	for(int i = 0; i < V; i++){
		visi[i] = false;
	}
	for(int i = 0; i < V; i++){
		if(!visi[i]){
			dfs2(i);
		}
	}
	for(int i = (int)ts.size() - 1; i >= 0; i--){
		printf("%d ", ts[i]);
	}
	printf("\n");

	return 0;
}