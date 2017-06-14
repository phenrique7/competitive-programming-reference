#include <bits/stdc++.h>

using namespace std;

const int C = 105;

int dp[C][C];

int main()
{
   char X[C], Y[C];
   
   scanf("%s", X);
   scanf("%s", Y);    
   int n = strlen(X);
   int m = strlen(Y);    
   for(int i = 0; i <= n; i++){
      dp[i][0] = 0;
   }    
   for(int j = 0; j <= m; j++){
      dp[0][j] = 0;
   }    
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
         if(X[i - 1] == Y[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
         }
         else{
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
         }
      }
   }        
   printf("%d\n", dp[n][m]);

   return 0;
}
