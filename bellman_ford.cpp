#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100;   //Numero maximo de vertices
const int MMAX = 10000; //Numero maximo de arestas
const int INF = 1e9;

int d[NMAX], pai[NMAX];
int orig[MMAX], dest[MMAX], peso[MMAX];

/* s: origem, n: numero de vertices, m: numero de arestas
retorna true se o grafo nao tem ciclo negativo, 0 c.c */
bool bellman_ford(int s, int n, int m){
   for(int i = 0; i < n; i++){
   	d[i] = INF;
   	pai[i] = -1;
   }
   d[s] = 0;
   for(int i = 0; i < n - 1; i++){
      for(int j = 0; j < m; j++){
         int u = orig[j], v = dest[j], w = peso[j];
         if(d[v] > d[u] + w){
        		d[v] = d[u] + w;
        		pai[v] = u;
         }
   	}
   }
   for(int j = 0; j < m; j++){
  		int u = orig[j], v = dest[j], w = peso[j];
  		if(d[v] > d[u] + w){
         return false;
      }
   }
   return true;
}

int main()
{
	int nn, mm;

   scanf("%d %d", &nn, &mm);
   int k = 0;
   for(int xx, yy, cst, i = 0; i < m; i++){
      scanf("%d %d %d", &xx, &yy, &cst);
      orig[k] = x; dest[k] = y; peso[k] = cst;
      k++;
   }
   int xx, yy;
   scanf("%d %d", &xx, &yy);
   bellman_ford(xx, nn, mm);
   printf("%d\n", d[yy]);

   return 0;
}
