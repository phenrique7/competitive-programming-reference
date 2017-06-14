#include <stdio.h>
#include <string.h>

const int C = 100005;

char str[C];

bool palindrome(){
	int esq = 0, dir = strlen(str) - 1;
	while(esq <= dir){
		if(str[esq] != str[dir]){
			return false;
		}
		esq++; dir--;
	}
	return true;
}

int main()
{
	while(gets(str)){
   	bool ans = palindrome();
   	printf("%s palindrome\n", ans ? "It is" : "It's not");
	}

	return 0;
}
