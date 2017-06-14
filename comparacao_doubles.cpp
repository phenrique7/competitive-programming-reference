#include <bits/stdc++.h>

const double EPS = 1e-9;

bool menor(double d1, double d2){
	return d1 < d2 - EPS;
}

bool menorOuIgual(double d1, double d2){
	return d1 <= d2 + EPS;
}

bool maior(double d1, double d2){
	return d1 > d2 + EPS;
}

bool maiorOuIgual(double d1, double d2){
	return d1 >= d2 - EPS;
}

bool igual(double d1, double d2){
	return d1 >= d2 - EPS && d1 <= d2 + EPS;
}

/*
bool igual(double a, double b)
{
    return fabs(a - b) < EPS;
}
*/

int main()
{
	return 0;
}
