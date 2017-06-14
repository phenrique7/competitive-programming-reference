#include <bits/stdc++.h>

using namespace std;

const int NMAX = 105;
const int UNVISITED = -1;

vector< vector<int> > g;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<bool> articulation_vertex;
int dfsCont, dfsRoot, rootChildren;

void articulationPointAndBridge(int u){
	dfs_low[u] = dfs_num[u] = dfsCont++;            // dfs_low[u] <= dfs_num[u]
	int sz = g[u].size();
	for(int j = 0; j < sz; j++){
		int v = g[u][j];
		if(dfs_num[v] == UNVISITED){                 // a tree edge
			dfs_parent[v] = u;
			if(u == dfsRoot){                         // special case if u is a root
				rootChildren++;
			}
			articulationPointAndBridge(v);
			if(dfs_low[v] >= dfs_num[u]){			      // for articulation point
				articulation_vertex[u] = true;    		// store this information first
			}
			if(dfs_low[v] > dfs_num[u]){      			// for bridge
				printf("  Edge (%d, %d) is a bridge\n", u, v);
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
		}
		else if(v != dfs_parent[u]){                 // a back edge and not direct cycle
			dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
		}
	}
}

int main()
{
	int V, E;

	/*
	Grafo da figura 4.6 lado direito (Competitive 3)
	6 6 
	0 1
	1 2
	1 3
	1 4
	1 5
	4 5
	*/

	scanf("%d %d", &V, &E);

	dfsCont = 0;
	dfs_num.assign(V, UNVISITED);
	dfs_low.assign(V, 0);
	dfs_parent.assign(V, 0);
	articulation_vertex.assign(V, false);

	g.resize(V);
	for(int x, y, i = 0; i < E; i++){
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	printf("Bridges:\n");
	for(int i = 0; i < V; i++){
		if(dfs_num[i] == UNVISITED){
			dfsRoot = i;
			rootChildren = 0;
			articulationPointAndBridge(i);
			articulation_vertex[dfsRoot] = (rootChildren > 1);  // special case
		}
	}
	printf("Articulation Points:\n");
	for(int i = 0; i < V; i++){
		if(articulation_vertex[i]){
			printf("  Vertex %d\n", i);
		}
	}

	return 0;
}