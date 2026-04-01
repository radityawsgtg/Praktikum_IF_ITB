#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

int main() {
    init();

    FILE *f1 = fopen("data1.txt", "r");
    if (f1 == NULL) return 1;
    
    int n;
    fscanf(f1, "%d", &n);
    int a[505];
    for (int i = 0; i < n; i++) {
        fscanf(f1, "%d", &a[i]);
    }
    fclose(f1);

    FILE *f2 = fopen("data2.txt", "r");
    if (f2 == NULL) return 1;
    
    int m;
    fscanf(f2, "%d", &m);
    int b[505];
    for (int i = 0; i < m; i++) {
        fscanf(f2, "%d", &b[i]);
    }
    fclose(f2);

    int c[1010];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < n) {
        c[k++] = a[i++];
    }

    while (j < m) {
        c[k++] = b[j++];
    }

    for (int x = 0; x < k; x++) {
        if (x > 0) {
            printf(" ");
        }
        printf("%d", c[x]);
    }
    printf("\n");

    return 0;
}