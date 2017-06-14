/*
	Edmonds-Karp
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int MAX_V = 40; // enough for sample graph in Figure 4.24/4.25/4.26/UVa 259
const int inf = 1e9;

vector<int> g[MAX_V];
int res[MAX_V][MAX_V];
int mf, f, s, t;                          // global variables
vi p;

void augment(int v, int minEdge){     // traverse BFS spanning tree from s to t
	if(v == s){
		f = minEdge;			// record minEdge in a global variable f
		return;
	}
	else if(p[v] != -1){ 
		augment(p[v], min(minEdge, res[p[v]][v])); // recursive
      res[p[v]][v] -= f; res[v][p[v]] += f;       // update
   }
}

int main()
{
	int V, k, vertex, weight;

	scanf("%d %d %d", &V, &s, &t);	
	memset(res, 0, sizeof res);
	for(int i = 0; i < V; i++){
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			scanf("%d %d", &vertex, &weight);
			g[i].push_back(vertex);
			g[vertex].push_back(i);
			res[i][vertex] = weight;
		}
	}
	mf = 0;                                              // mf stands for max_flow
	while(1){              // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
   	f = 0;
		// run BFS, compare with the original BFS shown in Section 4.2.2
		bitset<MAX_V> vis;
		vis[s] = true;
		queue<int> q;
		q.push(s);
		p.assign(MAX_V, -1);           // record the BFS spanning tree, from s to t!
		while(!q.empty()){
			int u = q.front();
			q.pop();
			if(u == t) break;      // immediately stop BFS if we already reach sink t
			int sz = g[u].size();
			for(int j = 0; j < sz; j++){
				int v = g[u][j];
				if(res[u][v] > 0 && !vis[v]){
					vis[v] = true;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, inf);     // find the min edge weight `f' along this path, if any
		if(f == 0) break;				// we cannot send any more flow (`f' = 0), terminate
		mf += f;                 // we can still send a flow, increase the max flow!
	}
	printf("%d\n", mf);                              // this is the max flow value

	return 0;
}

