#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
int v;
int minKey(int visited[], int key[]) {
  int min = -1, minIndex;
  for (int i = 0; i < v; i++) {
    if (!visited[i] && (min == -1 || key[i] < min)) {
      min = key[i];
      minIndex = i;
    }
  }
  return minIndex;
}
void prims(int graph[v][v]) {
  int key[v], visited[v], parent[v], u;
  for (int i = 0; i < v; i++) {
    key[i] = INT_MAX;
    visited[i] = 0;
  }
  key[0] = 0;
  parent[0] = -1;
  for (int i = 0; i < v-1; i++) {
    u = minKey(visited, key);
    visited[u] = 1;
    for (int j = 0; j < v; j++) {
      if (graph[u][j] && !visited[j] && graph[u][j] < key[j]) {
        parent[j] = u;
        key[j] = graph[u][j];
      }
    }
  }
  printf("edge weight:\n");
  for (int i = 1; i < v; i++)
  printf("%d - %d  %d\n", parent[i], i, graph[i][parent[i]]);
}
void main() {
  printf("enter number of vertices: ");
  scanf("%d", &v);
  int graph[v][v];
  printf("enter adjacency matrix:\n");
  for(int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      scanf("%d", &graph[i][j]);
    }
  }
  prims(graph);
}