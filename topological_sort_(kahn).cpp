#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > g;

int V;

void topologicalSort(){
   vector<int> in_degree(V, 0);  // Create a vector to store indegrees of all vertices. Initialize all indegrees as 0.
   /* Traverse adjacency lists to fill indegrees of vertices. This step takes O(V+E) time */
   for(int u = 0; u < V; u++){
      int sz = g[u].size();
      for(int v = 0; v < sz; v++){
         in_degree[g[u][v]]++;
      }
   } 
   
   queue<int> q; // Create an queue and enqueue all vertices with indegree 0
   for(int i = 0; i < V; i++){
      if(in_degree[i] == 0){
         q.push(i); 
      }
   }
   
   int cont = 0; // Initialize count of visited vertices

   vector<int> top_order;  // Create a vector to store result (A topological ordering of the vertices)
   
   while(!q.empty()){      // One by one dequeue vertices from queue and enqueue adjacents if indegree of adjacent becomes 0
      int u = q.front();    // Extract front of queue (or perform dequeue) and add it to topological order
      q.pop();
      top_order.push_back(u);      
      int sz = g[u].size(); // Visit all its neighbouring nodes of dequeued node u and decrease their in-degree by 1
      for(int j = 0; j < sz; j++){
         int v = g[u][j];
         in_degree[v]--;
         if(in_degree[v] == 0){ // If in-degree becomes zero, add it to queue
            q.push(v);
         }
      }
      cont++;
   }

   /* Check if there was a cycle */
   if(cont != V){
      cout << "There exists a cycle in the graph\n";
      return;
   }

   /* Print topological order */
   int sz = top_order.size();
   for(int i = 0; i < sz; i++){
      cout << top_order[i] << " ";
   }
   cout << endl;
}

int main()
{
   V = 6; // number of vertices
   g.resize(V);
   // aresta ao contrario, ou seja, adiciona aresta (u, v) se v depende de u
   g[5].push_back(2); 
   g[5].push_back(0);
   g[4].push_back(0);
   g[4].push_back(1);
   g[2].push_back(3);
   g[3].push_back(1);

   cout << "Following is a Topological Sort of\n";
   topologicalSort();

   return 0;
}