#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int N = 1005;

int nn, head, tail, start, finish, newBase;
int match[N], Queue[N], father[N], base[N];
bool inQueue[N], inPath[N], inBlossom[N];
vector< vector<int> > graph;

void createGraph(){
	int mm;
	scanf("%d %d", &nn, &mm);
	graph.resize(nn + 1);
	for(int u, v, i = 0; i < mm; i++){
		scanf("%d %d", &u, &v);
		graph[u].pb(v);
		graph[v].pb(u);
	}
}

void Push(int u){
	Queue[tail++] = u;
	inQueue[u] = true;
}

int Pop(){
	return Queue[head++];
}

int findCommonAncestor(int u, int v){
	memset(inPath, 0, sizeof(inPath));
	while(true){
		u = base[u];
		inPath[u] = true;
		if(u == start) break;
		u = father[match[u]];
	}
	while(true){
		v = base[v];
		if(inPath[v]) break;
		u = father[match[v]];
	}
	return v;
}

void resetTrace(int u){
	int v;
	while(base[u] != newBase){
		v = match[u];
		inBlossom[base[u]] = 1;
		inBlossom[base[v]] = 1;
		u = father[v];
		if(base[u] != newBase){
			father[u] = v;
		}
	}
}

void blossomContract(int u, int v){
	newBase = findCommonAncestor(u, v);
	memset(inBlossom, 0, sizeof(inBlossom));
	resetTrace(u);
	resetTrace(v);
	if(base[u] != newBase) father[u] = v;
	if(base[v] != newBase) father[v] = u;	
	for(u = 1; u <= nn; u++){
		if(inBlossom[base[u]]){
			base[u] = newBase;
			if(!inQueue[u]){
				Push(u);
			}
		}
	}
}

void findAugmentingPath(){
	memset(inQueue, false, sizeof(inQueue));
	memset(father, 0, sizeof(father));
	for(int u = 1; u <= nn; u++){
		base[u] = u;
	}
	head = 1; tail = 1;
	Push(start);
	finish = 0;
	while(head < tail){
		int u = Pop();
		int sz = graph[u].size();
		for(int i = 0; i < sz; i++){
			int v = graph[u][i];
			if(base[u] != base[v] && match[u] != v){
				if(v == start || (match[v] > 0 && father[match[v]] > 0)){
					blossomContract(u, v);
				}
				else if(father[v] == 0){
					father[v] = u;
					if(match[v] > 0){
						Push(match[v]);
					}
					else{
						finish = v;
						return;
					}
				}
			}
		}
	}
}

void augmentPath(){
	int u, v, w;
	u = finish;
	while(u > 0){
		v = father[u]; w = match[v];
		match[v] = u; match[u] = v;
		u = w;
	}
}

void Edmonds(){
   memset(match, 0, sizeof(match));
   for(int u = 1; u <= nn; u++){
   	if(match[u] == 0){
   		start = u;
   		findAugmentingPath();
   		if(finish > 0){
   			augmentPath();
   		}
   	}
   }
}

void printMatch(){
	int cont = 0;
	for(int u = 1; u <= nn; u++){
		if(match[u] > 0){
			cont++;
		}
	}
	if(cont == nn){ // emparelhamento perfeito
		printf("%d\n", cont / 2); // quantidade (minima) de arestas cobertas 
	}
	else{
		printf("%d\n", (cont / 2) + nn - cont);
	}
	/*
	for(int u = 1; u <= nn; u++){
		if(u < match[u]){
			printf("%d->%d\n", u, match[u]);
		}
	}
	*/
}

int main()
{
	int tt;
	scanf("%d", &tt);
	while(tt--){
   	createGraph();
   	Edmonds();
   	printMatch();	
		graph.clear();
	}

	return 0;
}