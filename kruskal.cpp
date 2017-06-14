#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

const int N = 100005;

int id[N], sz[N];

vector<ppi> g;

void init(int n){
   for(int i = 0; i < n; i++){
      id[i] = i; sz[i] = 1;
   }
}

int Find(int i){
   if(i == id[i]) return i;
   return id[i] = Find(id[i]);
}

void Union(int vv, int ww){
   vv = Find(vv); ww = Find(ww);
   if(vv == ww) return;
   if(sz[vv] > sz[ww]) swap(vv, ww);
   id[vv] = ww;
   if(sz[vv] == sz[ww]) sz[ww]++;
}

bool edgecmp(ppi a, ppi b){
   return a.second < b.second;
}

long long kruskal(int nn, int ee){
   long long cst = 0LL;

   init(nn);
   for(int i = 0; i < ee; i++){
      int uu = g[i].first.first;
      int vv = g[i].first.second;
      if(Find(uu) != Find(vv)){
         Union(uu, vv);
         cst += g[i].second;
      }
   }
   return cst;
}

int main()
{
	int nn, mm;

   while(scanf("%d %d", &nn, &mm), nn){
   	g.resize(mm);
   	for(int xx, yy, cst, i = 0; i < mm; i++){
   		scanf("%d %d %d", &xx, &yy, &cst);
   		g[i] = ppi(pii(xx, yy), cst); // cuidado quando vertices forem de 1 a nn - > pii(xx - 1, yy - 1)
   	}
   	sort(g.begin(), g.end(), edgecmp);
   	long long custo = kruskal(nn, mm);
   	printf("%Ld\n", custo);
   	g.clear();
   }   	

	return 0;
}
