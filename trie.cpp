#include <bits/stdc++.h>

using namespace std;

const int C = 85;
const int LETRAS = 30;

struct No{
	No *filho[LETRAS];
	int prefix_cont; // numero de prefixos comuns das strings da raiz ate o no.
	bool folha;
};

No * init(){
	No *novo = (No *)malloc(sizeof(No));
	novo->prefix_cont = 0;
	novo->folha = false;
 	for(int i = 0; i < 26; i++){
 		novo->filho[i] = NULL;
 	}
 	return novo;
}

No * constroi_trie(No *raiz, char str[]){
	No *atual = raiz;
	int sz = strlen(str);
	for(int i = 0; i < sz; i++){
   	int ch = str[i] - 'a';
   	if(atual->filho[ch] == NULL){
         atual->filho[ch] = init();
   	}
		atual->filho[ch]->prefix_cont++;
		atual = atual->filho[ch];
	}
   atual->folha = true;
	return raiz;
}

bool busca(No *atual, char str[]){
	int sz = strlen(str);
	for(int i = 0; i < sz; i++){
		int ch = str[i] - 'a';
		if(atual->filho[ch] == NULL){
			return false;
		}
		atual = atual->filho[ch];
	}
	return atual->folha;
}

void destroi_trie(No *atual){
	for(int i = 0; i < 26; i++){
		if(atual->filho[i] != NULL){
			destroi_trie(atual->filho[i]);
		}
	}
	free(atual);
	atual = NULL;
}

int main(){
	int n;
	char str[C];
	No *raiz = NULL;
	
	raiz = init();
	scanf("%d", &n);
	while(n--){
		scanf(" %s", str);
		raiz = constroi_trie(raiz, str);
	}
	scanf("%d", &n);
	while(n--){
		scanf(" %s", str);
		bool ret = busca(raiz, str);
		printf("%s\n", ret ? "Achou" : "Nao achou");
	}
	destroi_trie(raiz);

	return 0;
}