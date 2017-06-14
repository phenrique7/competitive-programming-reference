#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int bit[N][N]; /* Nao usar posicao 0 */
int nn; // nn se a matriz for quadrada, se nao, trocar nn por linha_max (rr) e coluna_max (cc)

int query(int x, int y){
   int sum = 0, yy = y;
   if(x == 0 || y == 0) return 0;
   while(x){
      while(y){
	      sum += bit[x][y];
   	   y -= y & (-y);
      }
      x -= x & (-x);
      y = yy;
   }
   return sum;
}

int query(int x1, int y1, int x2, int y2){
   return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}
/* v representa um inc/decremento em (x, y)! */
void update1(int x, int y, int val){
   int yy = y;
   if(x == 0 || y == 0) return;
   while(x <= nn){
      while(y <= nn){
         bit[x][y] += val;
         y += y & (-y);
      }
      x += x & (-x);
      y = yy;
   }
}

int get(int x1, int y1){
   return query(x1, y1, x1, y1);
}

void update(int x1, int y1, int val){
   update1(x1, y1, -get(x1, y1) + val);
}

int main()
{
	nn = N; // nn -> tamanho da matriz quadrada
   memset(bit, 0, sizeof(bit));
   update(3, 5, 2);
   update(2, 3, -1);
   printf("%d\n", query(1, 10, 1, 10));
   return 0;
}