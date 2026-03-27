#include <stdio.h>
#include <stdlib.h>

int main() {
    int kt = 0;
    int n, fav;
    int a[1000];
    int i, j;

    scanf("%d %d", &n, &fav);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == fav) {
            kt = 1;
        }
    }

    if (kt == 1) {
        printf("%d ", fav);
    }

    for (j = 0; j < n; j++) {
        printf("%d", a[j]);
        if (j < n - 1) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}