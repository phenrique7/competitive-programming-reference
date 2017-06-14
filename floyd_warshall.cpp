#include <bits/stdc++.h>

using namespace std;

const int NMAX = 405; // Usar ate com V <= 400
const int inf = 1e9;

int pd[NMAX][NMAX];

int main()
{
	int V, E;

	/*
	// Graph in Figure 4.20 (Competitive 3)
	5 9
	0 1 2
	0 2 1
	0 4 3
	1 3 4
	2 1 1
	2 4 1
	3 0 1
	3 2 3
	3 4 5
	*/

	scanf("%d %d", &V, &E);
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
	   	pd[i][j] = inf;
		}
		pd[i][i] = 0;
	}

	for(int u, v, w, i = 0; i < E; i++){
		scanf("%d %d %d", &u, &v, &w);
		pd[u][v] = w; // directed graph
	}

	for(int k = 0; k < V; k++){ // common error: remember that loop order is k->i->j
		for(int i = 0; i < V; i++){
	  		for(int j = 0; j < V; j++){
	     		pd[i][j] = min(pd[i][j], pd[i][k] + pd[k][j]);
	     	}
	   }
	}

	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
	   	printf("APSP(%d, %d) = %d\n", i, j, pd[i][j]);
	   }
	}

	return 0;
}