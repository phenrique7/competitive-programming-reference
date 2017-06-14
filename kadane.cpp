#include <bits/stdc++.h>

int v[] = {-2, -3, 4, -1, -2, 1, 5, -3};

/*Os elementos do vetor nao podem ser todos negativos*/
int kadane(int n){
   int max_atual = 0, max_total = 0;

   for(int i = 0; i < n; i++){
      max_atual += v[i];
      if(max_atual < 0){
         max_atual = 0;
      }
      if(max_atual > max_total){
         max_total = max_atual;
      }
   }
   return max_total;
}

int main()
{
   int n = sizeof(v) / sizeof(v[0]);
   int max = kadane(n);

   printf("Segmento com soma maxima %d\n", max);
}

/*
comentario: todos os elementos podem ser negativos

#define max(a, b) (a > b ? a : b)
 
int kadane(int n){
   int max_total = v[0];
   int max_atual = v[0];

   for(int i = 1; i < n; i++){
      max_atual = max(v[i], max_atual + v[i]);
      max_total = max(max_total, max_atual);
   }
   return max_total;
}
 

comentario: para saber o intervalo de maior soma

long long kadane(int n, int &x, int &y){
   long long max_atual, max_total;

   max_atual = 0;
   max_total = -1;
   int xx = 0;
   for(int i = 0; i < n; i++){
      max_atual += s[i];
      if(max_atual < 0){
         max_atual = 0;
         xx = i + 1;
      }
      if(max_atual >= max_total){
         max_total = max_atual;
         x = xx;
         y = i;
      }
   }

   return max_total;
}
*/