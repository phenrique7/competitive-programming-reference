#include <bits/stdc++.h>

using namespace std;

vector<int> dv;

void divisores(int n){
	int maxP = (int)sqrt(n);
	for(int i = 1; i <= maxP; ++i){ // para divisores proprios, i comeca de 2
		if(n % i == 0){
			int d1 = i;
			int d2 = n / i;
			if(d1 != d2){
				dv.push_back(d1);
				dv.push_back(d2);
			}
			else{
				dv.push_back(d1);
			}
		}
	}
}

int main()
{
	divisores(28);
	int sz = dv.size();
	for(int i = 0; i < sz; i++){
		printf("%d ", dv[i]);
	}
	printf("\n");

	return 0;
}