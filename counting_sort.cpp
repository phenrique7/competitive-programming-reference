#include <bits/stdc++.h>

const int MAX = 10000;
const int NMAX = 500;

int arr[MAX], B[MAX], C[NMAX];

void CountingSort(int A[], int N){
   
   int M = *std::max_element(A, A + N);
   
   for(int i = 0; i <= M; i++) C[i] = 0;
   for(int j = 0; j < N; j++) C[A[j]] = C[A[j]] + 1;
   for(int i = 1; i <= M; i++) C[i] = C[i] + C[i - 1];
   for(int j = N - 1; j >= 0; j--) B[--C[A[j]]] = A[j];   
   for(int i = 0; i < N; i++) printf("%d ", B[i]);
     
   printf("\n");
}
 
int main()
{
    int arr[] = {5, 2, 3, 0, 9, 1, 4, 10, 14, 6};

    CountingSort(arr, 10);
    
    return 0;
}

