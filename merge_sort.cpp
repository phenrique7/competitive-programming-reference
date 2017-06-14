#include <bits/stdc++.h>

const int inf = 1e6;
const int NMAX = 105;

int l[NMAX], r[NMAX];

int v[] = {inf, 2, 4, 5, 7, 1, 2, 3, 6, inf};

void merge(int p, int m, int q){               // m - meio
    int n1 = m - p + 1;
    int n2 = q - m;

    for(int i = 1; i <= n1; i++){
        l[i] = v[p + i - 1];
    }

    for(int i = 1; i <= n2; i++){
        r[i] = v[m + i];
    }

    l[n1 + 1] = r[n2 + 1] = inf;

    int i = 1, j = 1;
    for(int k = p; k <= q; k++){
        if(l[i] <= r[j]){
            v[k] = l[i++];
        }
        else{
            v[k] = r[j++];
        }
    }
}

void mergeSort(int p, int q){

    if(p < q){
        int meio = (p + q) / 2;
        mergeSort(p, meio);
        mergeSort(meio + 1, q);
        merge(p, meio, q);
    }
}

int main()
{    
    mergeSort(1, 8);

    for(int i = 1; i <= 8; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
  
    return 0;
}