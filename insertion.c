#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void Insertion(int a[], int n) {
    int x, j;
    for (int i = 1; i < n; i++) {
        x = a[i];
        j = i-1;
        while (j >= 0 && x < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
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
    Insertion(a, n);
    printf("sorted array: ");
    for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
}