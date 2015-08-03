#include <stdio.h>
#include <stdlib.h>
 
void merge (int *A, int n, int m) {
    int i=0, j=m, k=0;
    int *x = malloc(n * sizeof (int));
    for (k=0; k < n; k++) {
        if(j == n ){//bord
        x[k] = A[i++];
        } else if(A[j] < A[i] || i == m ){//bord
        x[k] = A[j++];
        } else {
        x[k] = A[i++];
        } 
    }
    int p;
    for (p = 0; p < n; p++) {
        A[p] = x[p];
    }
    free(x);
}
 
void merge_sort (int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}
 
int main () {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    merge_sort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
