#include <bits/stdc++.h>

using namespace std;

const int N = 100;

typedef vector< vector<int> > grafo;

grafo g;

int visi[N], pred[N], dist[N];

/* Usando lista de adjacencias */
void BFS(int s){
   queue<int> q;

   if(int i = 0; i < N; i++){
       visi[i] = false;
   }
   visi[s] = true;
   dist[s] = 0;
   q.push(s);
   while(!q.empty()){
      int a = q.front();
      q.pop();
 		int sz = g[a].size();
      for(int i = 0; i < sz; i++){
         if(!visi[g[a][i]]){
            visi[g[a][i]] = true;
            pred[g[a][i]] = a;
            dist[g[a][i]] = dist[a] + 1;
            q.push(g[a][i]);
         }
      }
   }
}

/* Usando matriz de adjacencias */
void bfs(int n, int s){
	int u;
	queue<int> q;

	for(int v = 0; v < n; v++){
		visi[v] = 0;
	}
	q.push(s);
	dist[s] = 0;
	visi[s] = 1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int v = 0; v < n; v++){
			if(grafo[u][v] == 1){
				if(visi[v] == 0){
					dist[v] = dist[u] + 1;
					pred[v] = u;
				    visi[v] = 1;
				    q.push(v);
				}
			}
		}
	}
}

int main()
{
   int a, v;
   
   cin >> v >> a;
   
   g.resize(v);   
   for(int x, y, i = 0; i < a; i++){
      cin >> x >> y;
      g[x].push_back(y);
      //g[x][y] = 1
   }   
   bfs(0);

   return 0;
}
