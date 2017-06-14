#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265359;
const double E = 2.71828182846;

//sqrt(2 * pi * n) * (n / e)^n; (Aproximacao do fatorial de n)
//0.5 * log10(2 * pi * n) + n * log10(n/e) + 1 (qtd de digitos do fatorial de n)

double fatAprox(int nn){
	return pow(E, -nn) * pow(nn, nn) * sqrt(2 * nn * PI);
}

int fatDigitos(int nn){
  	if(nn == 1){
  		return 1;
  	}
  	double ans = 0.5 * log10(2 * nn * PI) + nn * log10(nn / E) + 1;
  	return (int)ans;
}

int main()
{
	int nn;
	char str[100];

	scanf("%d", &nn);
	double ans = fatAprox(nn);
	sprintf(str, "Fatorial aproximado de %d: %lf", nn, ans);
	puts(str);
	int dig = fatDigitos(nn);
	cout << "Qtd de digitos de " << nn << ": " << dig << endl;

	return 0;
}