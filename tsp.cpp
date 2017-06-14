/* TSP (Competitive) Usando vertices como coordenadas */

#include <bits/stdc++.h>

using namespace std;

const double inf = (double)2e9;
const int N = 16;  // initial position + max N - 1 vertices
const int MAXBIT = 1 << N; 

int nn, x[N], y[N];
double dist[N][N], pd[N][MAXBIT + 5];

double tsp(int pos, int bitmask){ // bitmask stores the visited coordinates
	if(bitmask == (1 << (nn + 1)) - 1){
   	return dist[pos][0]; // return trip to close the loop
   }
	if(pd[pos][bitmask] != -1.0){
   	return pd[pos][bitmask];
   }
	double ans = inf;
	for(int nxt = 0; nxt <= nn; nxt++){ // O(n) here
		if(nxt != pos && !(bitmask & (1 << nxt))){ // if coordinate nxt is not visited yet
			ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
		}
	}
	return pd[pos][bitmask] = ans;
}

int main()
{
	scanf("%d", &nn);
	scanf("%d %d", &x[0], &y[0]); //initial position
	for(int i = 1; i <= nn; i++){ // karel's position is at index 0
		scanf("%d %d", &x[i], &y[i]);
	}
	for(int i = 0; i <= nn; i++){ // build distance table
		for(int j = 0; j <= nn; j++){
	  		dist[i][j] = hypot(x[i] - x[j], y[i] - y[j]); // Euclidian distance
	  		//dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]); Manhattan distance, dist[][] -> integers
	  	}
	}
	for(int i = 0; i <= nn; i++){
		for(int j = 0; j < MAXBIT; j++){
	  		pd[i][j] = -1.0;
	  	}
	}
	printf("%.2lf\n", tsp(0, 1));

	return 0;
}
