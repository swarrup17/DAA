#include <iostream>
#include <climits>
using namespace std;

#define V 9
int count = 0;

int minDistance(int dist[], bool sptSet[]) {
  int min = INT_MAX, min_index = -1;
  for (int v = 0; v < V; v++)
    if (!sptSet[v] && dist[v] <= min)
      min = dist[v], min_index = v, count += 4;
  count += 4;
  return min_index;
}

void printSolution(int dist[]) {
  cout << "Vertex \t Distance from Source\n";
  for (int i = 0; i < V; i++)
    cout << i << " \t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src) {
  int dist[V];
  bool sptSet[V];

  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;
  dist[src] = 0;
  count += 3;

  for (int i = 0; i < V - 1; i++) {
    int u = minDistance(dist, sptSet);
    sptSet[u] = true;
    count++;

    for (int v = 0; v < V; v++)
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v], count += 4;
  }

  printSolution(dist);
}
int main() {
int graph[V][V] = {
    {0, 5, 0, 0, 0, 0, 0, 9, 0},  // Node 0 (connected to nodes 1 and 7)
    {5, 0, 6, 0, 0, 0, 0, 13, 0}, // Node 1 (connected to nodes 0, 2, and 7)
    {0, 6, 0, 8, 0, 3, 0, 0, 1},  // Node 2 (connected to nodes 1, 3, 5, and 8)
    {0, 0, 8, 0, 11, 15, 0, 0, 0},// Node 3 (connected to nodes 2, 4, and 5)
    {0, 0, 0, 11, 0, 12, 0, 0, 0},// Node 4 (connected to nodes 3 and 5)
    {0, 0, 3, 15, 12, 0, 4, 0, 0},// Node 5 (connected to nodes 2, 3, 4, and 6)
    {0, 0, 0, 0, 0, 4, 0, 2, 7},  // Node 6 (connected to nodes 5, 7, and 8)
    {9, 13, 0, 0, 0, 0, 2, 0, 10},// Node 7 (connected to nodes 0, 1, 6, and 8)
    {0, 0, 1, 0, 0, 0, 7, 10, 0}  // Node 8 (connected to nodes 2, 6, and 7)
};


  dijkstra(graph, 0);
  cout << "Operation count: " << count << endl;

  return 0;
}