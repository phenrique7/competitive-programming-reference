#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int A[N][N];

int main()
{
	int nn, maxSubRect, subRect;
                       					     // O(n^4) DP solution, ~0.076s in UVa
	scanf("%d", &nn);                     // the dimension of input square matrix
	for(int i = 0; i < nn; i++){
		for(int j = 0; j < nn; j++){
			scanf("%d", &A[i][j]);
			if(i > 0) A[i][j] += A[i - 1][j];           // if possible, add from top
			if(j > 0) A[i][j] += A[i][j - 1];          // if possible, add from left
			if(i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];     // avoid double count
		}                                          // inclusion-exclusion principle
	}

	maxSubRect = -127*100*100;    // the lowest possible value for this problem
	for(int i = 0; i < nn; i++){
		for(int j = 0; j < nn; j++){ // start coordinate
			for(int k = i; k < nn; k++){
				for(int l = j; l < nn; l++){    // end coord
					subRect = A[k][l];      // sum of all items from (0, 0) to (k, l): O(1)
					if(i > 0) subRect -= A[i - 1][l];                              // O(1)
					if(j > 0) subRect -= A[k][j - 1];                              // O(1)
					if(i > 0 && j > 0) subRect += A[i - 1][j - 1];                 // O(1)
					maxSubRect = max(maxSubRect, subRect); // the answer is here
				}
			}
		}
	}
	printf("%d\n", maxSubRect);
	
	return 0;
}
