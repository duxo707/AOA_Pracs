#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void binary(int a[], int n, int s) {
  int l = 0, r = n-1, m;
  while (l <= r) {
    m = (l+r)/2;
    if (s == a[m]) {
      printf("\nnumber found at index %d", m);
      return;
    } else if (s < a[m]) {
      r = m-1;
    } else if (s > a[m]) {
      l = m+1;
    }
  }
  printf("\nnumber not found.");
}
void bubble(int a[], int n) {
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (a[j] > a[j+1]) {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}
void main() {
  int n, s;
  printf("enter length of array: ");
  scanf("%d", &n);
  int a[n];
  printf("enter array: ");
  for (int i = 0; i < n; i++)
  scanf("%d", &a[i]);
  printf("enter number to be searched: ");
  scanf("%d", &s);
  bubble(a, n);
  printf("sorted array: ");
  for (int i = 0; i < n; i++)
  printf("%d ", a[i]);
  binary(a, n, s);
}