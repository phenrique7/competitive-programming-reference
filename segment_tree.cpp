#include <bits/stdc++.h>

struct No{
	int esq, dir; // indices dos elementos cobertos por este nó.
	struct No *filho_esq, *filho_dir; // ponteiros para os nós que são filhos deste nó.
	int soma; // valor da soma de todos os elementos cobertos por este nó.
};

struct No * constroi(int *vetor, int esq, int dir){
	struct No *atual = (struct No *)malloc(sizeof(struct No));

	atual->esq = esq;
	atual->dir = dir;
	// [1] nó folha
	if(esq == dir) {
		atual->filho_esq = atual->filho_dir = NULL;
		// o intervalo é de um elemento, logo a soma é o elemento em si.
		atual->soma = vetor[esq];
	}
	// [2] nó não folha
	else{
		int meio = (esq + dir) / 2;
		atual->filho_esq = constroi(vetor, esq, meio);
		atual->filho_dir = constroi(vetor, meio + 1, dir);
		// a soma desse intervalo é igual a soma do intervalo dos filhos.
		atual->soma = atual->filho_esq->soma + atual->filho_dir->soma;
	}
	return atual;
}

int consulta(struct No *atual, int i, int j){
	// [1] completamente fora
	if(j < atual->esq || atual->dir < i){
		return 0;
	}
	// [2] completamente contido
	if(i <= atual->esq && atual->dir <= j){
		return atual->soma;
	}
	// [3] parcialmente contido
	return consulta(atual->filho_esq, i, j) + consulta(atual->filho_dir, i, j);
}

int atualiza(struct No *atual, int i, int j, int v){
	// [1] completamente fora
	if(j < atual->esq || atual->dir < i){
		return atual->soma;
	}
	// [2] chegou na folha
	if(atual->esq == atual->dir){
		atual->soma = v;
		return atual->soma;
	}
	// [3] parcial ou completamente contido
	atual->soma = atualiza(atual->filho_esq, i, j, v) + atualiza(atual->filho_dir, i, j, v);
	return atual->soma;
}

void funcao(struct No *atual){
	if(atual == NULL){
		return;
	}
	funcao(atual->filho_esq);
	printf("segmento [%d, %d] = %d\n", atual->esq, atual->dir, atual->soma);
	funcao(atual->filho_dir);
}

void destroi(struct No *atual){
	if(atual != NULL){
		destroi(atual->filho_esq);
		destroi(atual->filho_dir);
		free(atual);
		atual = NULL;
	}
}

int main()
{
	int vetor[] = {0, 1, 5, 3, 2, 9, 0, 3, 7}; //0 é ignorado
	int N = 8;

	struct No *raiz = constroi(vetor, 1, N);
	printf("consulta(1, 8) = %d\n", consulta(raiz, 1, 8));
	puts("\nAtualiza(1, 3, 2)\n");
	atualiza(raiz, 1, 3, 2);
	printf("consulta(1, 8) = %d\n\n", consulta(raiz, 1, 8));
	funcao(raiz);
	destroi(raiz);

	return 0;
}
