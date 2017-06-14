#include <bits/stdc++.h>

using namespace std;

const int M = 70;
const int N = 70;

int umate[M], m[M], d[M];
int vmate[N], ret[N];
int mm, nn, len;
vector<int> adj[M];

void bfs(){
	queue<int> q;
	len = mm;
	memset(m, 0, sizeof(m));
	for(int uu = 0; uu < mm; uu++){
		if(umate[uu] == -1){
			q.push(uu);
			m[uu] = 1;
			d[uu] = 0;
		}
	}
	while(!q.empty()){
		int uu = q.front(); q.pop();
		int sz = adj[uu].size();
		for(int i = 0; i < sz; i++){
			int vv = adj[uu][i];
			int ww = vmate[vv];
			if(ww == -1){
				len = d[uu];
				return;
			}
			else if(!m[ww]){
				q.push(ww);
				m[ww] = 1;
				d[ww] = d[uu] + 1;
			}
		}
	}
}

void augment(int vv){
	do{
		int uu = ret[vv];
		int ww = umate[uu];
		umate[uu] = vv;
		vmate[vv] = uu;
		vv = ww;
	}while(vv != -1);
}

int dfs(int uu){
	m[uu] = 1;
	int sz = adj[uu].size();
	for(int i = 0; i < sz; i++){
		int vv = adj[uu][i];
		int ww = vmate[vv];
		if(ww == -1){
			if(d[uu] == len){
				ret[vv] = uu;
				augment(vv);
				return 1;
			}
		}
		else if(d[uu] < d[ww] && !m[ww]){
			ret[vv] = uu;
			if(dfs(ww)){
			   return 1;
			}
		}
	}
	return 0;
}

int match(){
	memset(umate, -1, sizeof(umate));
	memset(vmate, -1, sizeof(vmate));	
	for(int uu = 0; uu < mm; uu++){
		int sz = adj[uu].size();
		for(int i = 0; i < sz; i++){
			int vv = adj[uu][i];
			if(vmate[vv] == -1){
				umate[uu] = vv;
				vmate[vv] = uu;
				break;
			}
		}
	}
	while(bfs(), len != mm){
		memset(m, 0, sizeof(m));
		for(int uu = 0; uu < mm; uu++){
			if(umate[uu] == -1){
				dfs(uu);
			}
		}
	}
	int matching = 0;
	for(int uu = 0; uu < mm; uu++){
		if(umate[uu] != -1){
			matching++;
		}
	}
	return matching;
}

int main()
{
	//conjunto A e B de tamanhos nn e mm ou conjunto A e B de tamnho mm e nn
	//adj[uu].push_back(vv);
	
	return 0;
}






