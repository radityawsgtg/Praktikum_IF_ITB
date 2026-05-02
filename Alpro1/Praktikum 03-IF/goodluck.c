#include <stdio.h>

int main() {
    int n;
    long long k;
    int a[10005];
    int r[10005];
    int i;
    long long j;

    scanf("%d %lld", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        r[i] = i;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            r[i] = a[r[i]];
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d", r[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}