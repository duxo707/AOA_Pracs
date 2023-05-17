#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#define infinity INT_MAX
int v = 0;
int minDist(int dist[], int visited[]) {
  int min = infinity, minIndex;
  for(int i = 0; i < v; i++) {
    if (visited[i] == 0 && dist[i] <= min) {
      min = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}
void dijkstra(int graph[v][v], int s) {
  int dist[v], visited[v], u;
  for(int i = 0; i < v; i++) {
    dist[i] = infinity;
    visited[i] = 0;
  }
  dist[s] = 0;
  for(int i = 0; i < v-1; i++) {
    u = minDist(dist, visited);
    visited[u] = 1;
    for(int j = 0; j < v; j++) {
      if (graph[u][j] && visited[j] == 0 && dist[u] != infinity && dist[u]+graph[u][j] < dist[j])
      dist[j] = dist[u] + graph[u][j];
    }
  }
  printf("vertex, distance from source\n");
  for (int i = 0; i < v; i++)
  printf("%d\t%d\n", i, dist[i]);
}
void main() {
  int s;
  printf("enter number of vertices: ");
  scanf("%d", &v);
  int graph[v][v];
  printf("enter adjacency matrix: ");
  for(int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++)
    scanf("%d", &graph[i][j]);
  }
  printf("enter source: ");
  scanf("%d", &s);
  dijkstra(graph, s);
}