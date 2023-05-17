#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void quick(int a[], int first, int last) {
  int pivot, i, j, temp;
  if (first < last) {
    pivot = first;
    i = first;
    j = last;
    while (i < j) {
      while (a[i] <= a[pivot] && i < last)
      i++;
      while (a[j] > a[pivot] && j > first)
      j--;
      if (i < j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
    temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;
    quick(a, first, j-1);
    quick(a, j+1, last);
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
  quick(a, 0, n-1);
  printf("sorted array: ");
  for (int i = 0; i < n; i++)
  printf("%d ", a[i]);
}