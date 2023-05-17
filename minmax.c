#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int min, max;
void minMax(int a[], int l, int r) {
  int max_, min_, m;
  if (l == r) {
    min = a[l];
    max = a[l];
  } else if (l == r-1) {
    if (a[l] < a[r]) {
      max = a[r];
      min = a[l];
    } else {
      max = a[l];
      min = a[r];
    }
  } else {
    m = (l+r)/2;
    minMax(a, l, m);
    max_ = max;
    min_ = min;
    minMax(a, m+1, r);
    if (max < max_)
    max = max_;
    if (min > min_)
    min = min_;
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
  max = a[0];
  min = a[0];
  minMax(a, 0, n-1);
  printf("minimum element: %d\n", min);
  printf("maximum element: %d", max);
}