#include <bits/stdc++.h>

const int NMAX = 2; // Fibonacci matrix, increase/decrease this value as needed

struct Matrix{
   long long mat[NMAX][NMAX];
};
// we will return a 2D array
Matrix matMul(Matrix a, Matrix b){ // O(n^3)
   Matrix ans;
   int k;

   for(int i = 0; i < NMAX; i++){
      for(int j = 0; j < NMAX; j++){
         for(ans.mat[i][j] = k = 0; k < NMAX; k++){
            ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
         }
         //ans.mat[i][j] %= MOD; (se necessario, mas pode dar WA)
      }
   }
   return ans;
}

// if necessary, use modulo arithmetic
Matrix matPow(Matrix base, long long p){ // O(n^3 log p)
   Matrix ans; 

   for(int i = 0; i < NMAX; i++){
      for(int j = 0; j < NMAX; j++){
         ans.mat[i][j] = (i == j); // prepare identity matrix
      }
   }   
   while(p){// iterative version of Divide & Conquer exponentiation
      if(p & 1){// if p is odd (last bit is on)
         ans = matMul(ans, base);
      }
      base = matMul(base, base); // square the base
      p >>= 1; // divide p by 2
   }
   return ans; 
}

int main()
{
   Matrix mm, ma;

   mm.mat[0][0] = 1;
   mm.mat[0][1] = 1;
   mm.mat[1][0] = 1;
   mm.mat[1][1] = 0;

   ma = matPow(mm, 10);

   for(int i = 0; i < NMAX; i++){
      for(int j = 0; j < NMAX; j++){
         printf("%Ld ", ma.mat[i][j]);
      }
      printf("\n");
   }

   return 0;
}
