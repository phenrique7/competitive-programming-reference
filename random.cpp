#include <bits/stdc++.h>

int random(int min, int max){
	int ans = min + (rand() % (int)(max - min + 1));
	return ans;
}

int main()
{
	srand(time(NULL));

	for(int i = 1; i <= 20; i++){
		printf("%d\n", random(1, 3));
	}
	
	return 0;
}
