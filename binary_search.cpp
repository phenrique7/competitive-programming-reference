#include <stdio.h>
#include <stdlib.h>

int v[] = {50, 20, 60, 40, 10, 30};

int compare(const void *a, const void *b){ return (*(int*)a - *(int*)b); }

int buscaBinaria(int nn, int chave){
	int esq = 0, dir = nn - 1;

	while(esq <= dir){
		int meio = esq + (dir - esq) / 2;
		if(v[meio] == chave){
			/* encontrar primeira ocorrencia
  			while(meio - 1 != -1 && chave == p[meio - 1]){
				meio--;  				
  			}
  			*/
			return meio;
		}
		else if(chave < v[meio]){
			dir = meio - 1;
		}
		else{
			esq = meio + 1;
		}
	}
	//return esq == nn ? -1 : esq; retorna o elemento mais proximo a direita da chave
	//return dir; retorna o elemento mais proxima a esquerda da chave
	return -1;
}

int main()
{
	int chave = 40;

	qsort(v, 6, sizeof(int), compare);
	printf("%d is in the array.\n", buscaBinaria(6, chave));

	return 0;
}
