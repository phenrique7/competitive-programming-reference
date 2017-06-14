#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char g[N][N];

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int R, C;

int bfsFloodFill(int sr, int sc, char c1, char c2){
	queue< pair<int, int> > f;

	f.push(make_pair(sr, sc));
	int ans = 0;
   while(!f.empty()){
      int rr = f.front().first;
      int cc = f.front().second;
      f.pop();
      for(int d = 0; d < 8; d++){
        	int r = rr + dr[d];
        	int c = cc + dc[d];
        	if(r < 0 || r >= R || c < 0 || c >= C){
		      continue;
	      }
         if(g[r][c] != c1){
		      continue;
 			}
 			ans++;
 			f.push(make_pair(r, c));
      	g[r][c] = c2;
      }
   }

   return ans;
}

int main()
{
	int tt;

	scanf("%d", &tt);
	while(tt--){
		scanf("%d %d", &R, &C);
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				scanf(" %c", &g[i][j]);
			}
		}		
		int rr, cc;
		scanf("%d %d", &rr, &cc);
   	int ans = bfsFloodFill(rr, cc, 'W', '.');
   	printf("ans = %d\n", ans);
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				printf("%c", g[i][j]);
			}
			printf("\n");
		}
	}

   return 0;
}