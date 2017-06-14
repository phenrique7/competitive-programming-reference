#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

const int inf = 1e9;
const int N = 105;

int cor[N];
vector< vector<int> > g;

bool ehBipartido(int ss, int nn){
	queue<int> q;	
	for(int i = 0; i < nn; i++){
		cor[i] = inf;
	}
	cor[ss] = 0;
	q.push(ss);
	while(!q.empty()){               // similar to the original BFS routine
		int u = q.front();
		q.pop();
		int sz = g[u].size();
		for(int j = 0; j < sz; j++){
			int v = g[u][j];
			if(cor[v] == inf){         // but, instead of recording distance,
				cor[v] = 1 - cor[u];    // apenas usa duas cores {0, 1}
				q.push(v);
			}
			else if(cor[v] == cor[u]){ // u & v.first has same cor we have a coring conflict
				return false;
			}
		}
	}

	return true;
}

int main()
{
	g.resize(4);

	g[0].push_back(1);
	g[1].push_back(0);

	g[0].push_back(2);
	g[2].push_back(0);

	g[0].push_back(3);
	g[3].push_back(0);

	g[1].push_back(3);
	g[3].push_back(1);

	g[2].push_back(3);
	g[3].push_back(2);

	bool ret = ehBipartido(0, 4);

	if(ret){
		puts("Eh Bipartido");
	}
	else{
		puts("Nao eh bipartido");
	}

	return 0;
}