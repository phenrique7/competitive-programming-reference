/*
	Edmonds-Karp
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 105;
const int inf = 1e9;

int cap[MAX_V][MAX_V];
int parnt[MAX_V];
vector<int> g[MAX_V];

int maxflow(int s, int t){
   int mf = 0;
   while(1){
		memset(parnt, -1, sizeof(parnt));
		parnt[s] = -2;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int v = q.front(); q.pop();
			if(v == t){
				break;
			}
			int sz = g[v].size();
			for(int i = 0; i < sz; i++){
				int w = g[v][i];
				if(parnt[w] == -1 && cap[v][w] > 0){
					parnt[w] = v;
					q.push(w);
				}
			}
		}
		if(parnt[t] == -1) break;
		int bot = inf;
		for(int v = t, w = parnt[t]; w >= 0; v = w, w = parnt[w]){
			bot = min(bot, cap[w][v]);
		}
		for(int v = t, w = parnt[t]; w >= 0; v = w, w = parnt[w]){
			cap[w][v] -= bot;
			cap[v][w] += bot;
		}
		mf += bot;
   }
   return mf;
}

int main()
{
   int nn, mm, kk;
   int inst = 1;
   
   while(scanf("%d %d %d", &nn, &mm, &kk) != EOF){
  		memset(cap, 0, sizeof(cap));
  		/* se o grafo for bipartido:
			int s = 0;
			int t = nn + mm + 1;
			int nv = t + 1;
		*/
		for(int i = 0; i <= nv; i++){
			g[i].clear();
		}
      for(int uu, vv, qq = 1; qq <= kk; qq++){
         scanf("%d %d", &uu, &vv); // uu -> vert. do conjunto A, vv -> vert. do conjunto B
         /*
         g[uu].push_back(vv);
         g[vv].push_back(uu);
         cap[uu][vv] += 1;
         */
      }		
		int ans = maxflow(s, t);
   }
   
   return 0;
}