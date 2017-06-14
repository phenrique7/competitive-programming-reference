#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

// B1 and B2 are two fenwick trees
// Original array entries are assumed to be 0
// and only updates are stored.
long long B1[N], B2[N];

// Array size
int nn;

// Point query
// Returns value at position b in the array for ft = B1
// Returns value to be subtracted from query(B1, b) * b for ft = B2
long long query(long long *ft, int b){
	long long sum = 0;
	for(; b; b -= b&(-b)) sum += ft[b];
	return sum;
}

// Range query: Returns the sum of all elements in [1...b]
long long query(int b){
   return query(B1, b) * b - query(B2, b);
}

// Range query: Returns the sum of all elements in [i...j]
long long range_query(int i, int j){
   return query(j) - query(i - 1);
}

// Point update: Adds v to the value at position k in the array
// ft is the fenwick tree which represents that array
void update(long long *ft, int k, long long v){
	for(; k <= N; k += k&(-k)) ft[k] += v;
}

// Range update: Adds v to each element in [i...j]
void range_update(int i, int j, long long v){
	update(B1, i, v);
	update(B1, j + 1, -v);
	update(B2, i, v * (i - 1));
	update(B2, j + 1, -v * j);
}

int main()
{
	int tt, qq, op;
	long long val;

	scanf("%d", &tt);
	while(tt--){
		// qq -> No. of operations
		scanf("%d %d", &nn, &qq);
		memset(B1, 0, (nn + 1) * sizeof(long long));
		memset(B2, 0, (nn + 1) * sizeof(long long));
		while(qq--){
			int p, q;
			scanf("%d %d %d", &op, &p, &q);
			// op is 0 for a range update and 1 for a range query
			if(op == 0){
       		scanf("%lld", &val);
       		range_update(p, q, val);
			}
			else{
         	printf("%lld\n", range_query(p, q));
         }
		}
	}

   return 0;
}
