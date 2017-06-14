#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char g[N][N];

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int R, C;

int dfsFloodFill(int r, int c, char c1, char c2){
   if(r < 0 || r >= R || c < 0 || c >= C){
      return 0;
   }
   if(g[r][c] != c1){
      return 0;
   }
   int ans = 1;
   g[r][c] = c2;
   for(int d = 0; d < 8; d++){
      ans += floodfill(r + dr[d], c + dc[d], c1, c2);
   }
   return ans;
}

int main()
{
   int rr, cc;
   int ans = dfsFloodFill(rr, cc, 'W', '.');    

   return 0;
}