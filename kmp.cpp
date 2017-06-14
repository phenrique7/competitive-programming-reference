#include <bits/stdc++.h>

const int N = 100000;
const int M = 10000;

int back[M];
char text[N], patt[M];

void build(char *p){
	int m = strlen(p);
	int j = back[0] = -1;
	for(int i = 1; i < m; i++){
		while(j >= 0 && p[j + 1] != p[i]){
			j = back[j];
		}
		j++;
		back[i] = j;
	}
}

void kmp(char *t, char *p){
	int m = strlen(p), n = strlen(t);
	build(p);
	for(int j = -1, i = 0; i < n; i++){
		while(j >= 0 && t[i] != p[j + 1]){
			j = back[j];
		}
		j++;
		if(j == m - 1){	// achou em t[i-m+1 .. i] 
			printf("%d ocorrencia achou em t[%d .. %d]\n", cont++, i - m + 1, i);
			j = back[j];
		}
	}
}

int main()
{
	gets(text);
	gets(patt);
	kmp(text, patt);

	return 0;
}