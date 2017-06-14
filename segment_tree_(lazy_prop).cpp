#include <bits/stdc++.h>

const int N = 300000; // Para nn <= 100000

long long lazy[N];

struct No{
	int esq, dir;
	long long soma;
	struct No *filho_esq, *filho_dir;
};

struct No * constroi(int esq, int dir){
   struct No *atual = (struct No *)malloc(sizeof(struct No));
   atual->esq = esq;
   atual->dir = dir;
   if(esq == dir){
      atual->filho_esq = atual->filho_dir = NULL;
   }
   else{
      int meio = (esq + dir) / 2;
      atual->filho_esq = constroi(esq, meio);
      atual->filho_dir = constroi(meio + 1, dir);
   }
	atual->soma = 0LL;
   return atual;
}

long long consulta(int node, struct No *atual, int i, int j){	
	if(lazy[node] != 0){
		atual->soma += (atual->dir - atual->esq + 1) * lazy[node];
		if(atual->filho_esq != NULL){
		    lazy[2 * node] += lazy[node];
		    lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0LL;
	}
   if(j < atual->esq || atual->dir < i){
      return 0;
   }
   if(i <= atual->esq && atual->dir <= j){
      return atual->soma;
   }
   return consulta(2 * node, atual->filho_esq, i, j) + consulta(2 * node + 1, atual->filho_dir, i, j);   
}

long long atualiza(int node, struct No *atual, int i, int j, long long valor){	
	if(lazy[node] != 0){
		atual->soma += (atual->dir - atual->esq + 1) * lazy[node];
		if(atual->filho_esq != NULL){
   		lazy[2 * node] += lazy[node];
   	   lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0LL;
	}
	if(j < atual->esq || atual->dir < i){
		return atual->soma;
	}
	if(i <= atual->esq && atual->dir <= j){
		atual->soma += (atual->dir - atual->esq + 1) * valor; // incrementa do valor anterior. Para atualizar sem incremento troca o '+=' por '='
		if(atual->filho_esq != NULL){
         lazy[2 * node] += valor; // incrementa do valor anterior. Para atualizar sem incremento troca o '+=' por '='
         lazy[2 * node + 1] += valor; // incrementa do valor anterior. Para atualizar sem incremento troca o '+=' por '='
      }
		return atual->soma;
	}
   atual->soma = atualiza(2 * node, atual->filho_esq, i, j, valor) + atualiza(2 * node + 1, atual->filho_dir, i, j, valor);
	return atual->soma;
}

int main()
{
   int nn, query, p, q;
	long long v, r;

	scanf("%d %d", &nn, &query);
   memset(lazy, 0, sizeof lazy); //começa com todos os elementos zerados
	struct No *raiz = constroi(1, nn);
	for(int op, qq = 1 qq <= query; qq++){
		scanf("%d %d %d", &op, &p, &q); // c -> 0 (atualiza) ou 1 (consulta) / p -> limite esquerda / q -> limite direita
		if(op == 0){
			scanf("%Ld", &v);
			r = atualiza(1, raiz, p, q, v); // v -> valor de atualizacao
		}
		else{
			r = consulta(1, raiz, p, q);
			printf("%Ld\n", r);
		}
	}

   return 0;
}
