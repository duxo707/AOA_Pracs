#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void selection(int a[], int n) {
  int min, temp;
  for (int i = 0; i < n-1; i++) {
    min = i;
    for (int j = i+1; j < n; j++) {
      if (a[j] < a[min])
      min = j;
    }
    temp = a[min];
    a[min] = a[i];
    a[i] = temp;
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
  selection(a, n);
  printf("sorted array: ");
  for (int i = 0; i < n; i++)
  printf("%d ", a[i]);
}