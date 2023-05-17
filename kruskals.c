#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
int v;
int find(int p, int parent[]) {
  while(parent[p])
  p = parent[p];
  return p;
}
int uni(int x, int y, int parent[]) {
  if (x != y) {
    parent[y] = x;
    return 1;
  }
  return 0;
}
void main() {
  int ne = 1, a, b, x, y, min, minCost = 0;
  printf("enter number of vertices: ");
  scanf("%d", &v);
  int graph[v][v], parent[v];
  printf("enter adjacency matrix:\n");
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      scanf("%d", &graph[i][j]);
      if (graph[i][j] == 0)
      graph[i][j] = INT_MAX;
    }
  }
  while (ne < v) {
    for (int i = 0, min = INT_MAX; i < v; i++) {
      for (int j = 0; j < v; j++) {
        if (graph[i][j] < min) {
          min = graph[i][j];
          a = x = i;
          b = y = j;
        }
      }
    }
    x = find(x, parent);
    y = find(y, parent);
    if (uni(x, y, parent)) {
      printf("edge (%d, %d) = %d", a, b, min);
      minCost += min;
      ne++;
    }
    graph[a][b] = graph[b][a] = INT_MAX;
  }
  printf("\nminimum cost: ", minCost);
}