#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

vector< vector<int> > g, gt;
stack<int> p;
bool visi[N];
int nn;

void DFSGt(int uu){
	visi[uu] = true;
	printf("%d ", uu);
	int sz = gt[uu].size();
	for(int vv = 0; vv < sz; vv++){
		if(!visi[gt[uu][vv]]){
			DFSGt(gt[uu][vv]);
		}
	}
}
 
void GTransposto(){
	for(int uu = 0; uu < nn; uu++){
		int sz = g[uu].size();
		for(int vv = 0; vv < sz; vv++){
			gt[g[uu][vv]].push_back(uu);
		}
	}
}
 
void DFSG(int v){
	visi[v] = true;
	for(int i = 0; i < (int)g[v].size(); ++i){
		if(!visi[g[v][i]]){
			DFSG(g[v][i]);
		}
	}
	p.push(v);
}
 
void SCC(){ 
	for(int i = 0; i < nn; i++){
		visi[i] = false;
	}
	for(int i = 0; i < nn; i++){
		if(!visi[i]){
			DFSG(i);
		}
	}
	GTransposto();
	for(int i = 0; i < nn; i++){
		visi[i] = false;
	}
	while(!p.empty()){
		int vv = p.top();
		p.pop();
		if(!visi[vv]){
			DFSGt(vv);
			printf("\n");
		}
	}
}
 
int main()
{
	// Cria um grafo e o seu transposto com 5 vertices
	nn = 5;

	g.resize(nn);
	gt.resize(nn);

	g[1].push_back(0);
	g[0].push_back(2);
	g[2].push_back(1);
	g[0].push_back(3);
	g[3].push_back(4);

	puts("Segue as componentes fortemente conectados do grafo");

	SCC();

	return 0;
}
