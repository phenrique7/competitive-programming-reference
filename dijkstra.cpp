#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 105;
const int inf = 1e9;

int pred[N],  dist[N];
int g[N][N];

void dijkstra(int s, int n){
	set<pii> q;

	for(int v = 0; v < n; v++){
	  dist[v] = inf;
	}
	dist[s] = 0;
	pred[s] = -1;
	q.insert(make_pair(0, s));
	while(!q.empty()){
		int u = q.begin()->second;
		q.erase(q.begin());
		for(int v = 0; v < n; v++){
			if(g[u][v] != inf){
				if(dist[u] + g[u][v] < dist[v]){
					if(dist[v] != inf){
						q.erase(q.find(pii(dist[v], v)));
					}
					dist[v] = dist[u] + g[u][v];
					pred[v] = u;
					q.insert(pii(dist[v], v));
				}
			}
		}
	}
}

int main()
{
	int nn = 5;

	for(int i = 0; i <= nn; i++){
		for(int j = 0; j <= nn; j++){
			g[i][j] = inf;
		}
	}

	g[0][1] = 10; g[0][2] = 5;
	g[1][2] = 3; g[1][3] = 1;
	g[2][1] = 2; g[2][3] = 9;
	g[2][4] = 8; g[3][4] = 4;
	g[4][3] = 6;
	
	printf("%d\n", dijkstra(0, 4, nn));
	for(int i = 0; i < nn; i++){
		printf("pred[%d] = %d\n", i, pred[i]);
	}
	printf("\n");
	for(int i = 0; i < nn; i++){
		printf("dist[%d] = %d\n", i, dist[i]);
	}

	return 0;
}
