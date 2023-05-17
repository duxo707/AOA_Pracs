#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void merge(int a[], int l, int m, int r) {
  int n1 = m-l+1, n2 = r-m;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++)
  L[i] = a[l+i];
  for (int i = 0; i < n2; i++)
  R[i] = a[m+i+1];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}
void mergeSort(int a[], int l, int r) {
  if (l < r) {
    int m = l+(r-l)/2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
  }
}
void main() {
  int n;
  printf("enter length of array: ");
  scanf("%d", &n);
  int a[n];
  printf("enter elements of array: ");
  for (int i = 0; i < n; i++)
  scanf("%d", &a[i]);
  mergeSort(a, 0, n-1);
  printf("sorted array: ");
  for (int i = 0; i < n; i++)
  printf("%d ", a[i]);
}