/**
 * Segment Tree que armazena e calcula o valor máximo de um range
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */
 
#include <bits/stdc++.h>

using namespace std;
  
const int MAX = 65;
const int inf = 0x7fffffff;
 
int tree[MAX];
int arr[] = {1, 5, 3, 2, 9, 0, 3, 7};

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b){

    if(a > b) return; // Out of range
  	
  	if(a == b){ // Leaf node
    	tree[node] = arr[a]; // Init value
		return;
	}
	
	int meio = (a + b) / 2;
	build_tree(node * 2, a, meio); // Init left child
	build_tree(node * 2 + 1, meio + 1, b); // Init right child
	
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // Init root value
}
 
/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {
    
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a == b){ // Leaf node
    	tree[node] += value;
    	return;
	}
 
	int meio = (a + b) / 2;
	update_tree(node * 2, a, meio, i, j, value); // Updating left child
	update_tree(node * 2 + 1, meio + 1, b, i, j, value); // Updating right child
 
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // Updating root with max value
}
 
/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -inf; // Out of range
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];
	
	int meio = (a + b) / 2;
	int q1 = query_tree(node * 2, a, meio, i, j); // Query left child
	int q2 = query_tree(node * 2 + 1, meio + 1, b, i, j); // Query right child
 
	int res = max(q1, q2); // Return final result
	
	return res;
}
 
int main()
{
	int N = 8;

	build_tree(1, 0, N - 1);
 
	cout << query_tree(1, 0, N - 1, 0, N - 1) << endl << endl; // Get max element in range [0, N-1]
	
	update_tree(1, 0, N - 1, 0, 6, 3); // Increment range [0, 6] by 3
	update_tree(1, 0, N - 1, 6, 7, 2); // Incremenet range [6, 7] by 2
	update_tree(1, 0, N - 1, 5, N - 1, 10); // Increment range [5, N-1] by 10
 
	cout << query_tree(1, 0, N - 1, 0, N - 1) << endl; // Get max element in range [0, N-1]

	return 0;
}