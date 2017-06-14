#include <bits/stdc++.h>

using namespace std;

class FenwickTree{
   public:
      FenwickTree(){}
      // initialization: n + 1 zeroes, ignore index 0
      FenwickTree(int n){
      	ft.assign(n + 1, 0LL);
      }
      long long rsq(int b){                                     // returns RSQ(1, b)
         long long sum = 0; 
         for(; b; b -= b&(-b)){
         	sum += ft[b];
         }
         return sum;
      }
      long long rsq(int a, int b){                              // returns RSQ(a, b)
         return rsq(b) - (a == 1 ? 0LL : rsq(a - 1));
      }
      // updates value of the k-th element by v (v can be +ve/inc or -ve/dec)
      void update(int k, int v){                    // note: n = ft.size() - 1
         for(; k < (int)ft.size(); k += k&(-k)){
         	ft[k] += v;
         }
      }

   private:
   	vector<long long> ft;
};

int main()
{                          // idx   0 1 2 3 4 5 6 7  8 9 10, no index 0!
   FenwickTree ft(10);     // ft = {-,0,0,0,0,0,0,0, 0,0,0}
   ft.update(2, 1);        // ft = {-,0,1,0,1,0,0,0, 1,0,0}, idx 2,4,8 => +1
   ft.update(4, 1);        // ft = {-,0,1,0,2,0,0,0, 2,0,0}, idx 4,8 => +1
   ft.update(5, 2);        // ft = {-,0,1,0,2,2,2,0, 4,0,0}, idx 5,6,8 => +2
   ft.update(6, 3);        // ft = {-,0,1,0,2,2,5,0, 7,0,0}, idx 6,8 => +3
   ft.update(7, 2);        // ft = {-,0,1,0,2,2,5,2, 9,0,0}, idx 7,8 => +2
   ft.update(8, 1);        // ft = {-,0,1,0,2,2,5,2,10,0,0}, idx 8 => +1
   ft.update(9, 1);        // ft = {-,0,1,0,2,2,5,2,10,1,1}, idx 9,10 => +1
   printf("%lld\n", ft.rsq(1, 1));  // 0 => ft[1] = 0
   printf("%lld\n", ft.rsq(1, 2));  // 1 => ft[2] = 1
   printf("%lld\n", ft.rsq(1, 6));  // 7 => ft[6] + ft[4] = 5 + 2 = 7
   printf("%lld\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
   printf("%lld\n", ft.rsq(3, 6));  // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1

   ft.update(5, 2); // update demo (a funcao incrementa ou decrementa do valor que esta na posicao)
   /*
    * Para atualizar uma posicao com um valor, faz:
		int aux = ft.rsq(pos, pos);
		ft.update(pos, valor - aux);
	*/
   printf("%d\n", ft.rsq(1, 10)); // now 13

   return 0;	
}
