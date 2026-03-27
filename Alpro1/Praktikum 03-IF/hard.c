#include <stdio.h>

int hitung_digit(int x) {
    int count = 0;
    if (x == 0) return 1;
    while (x > 0) {
        count++;
        x /= 10;
    }
    return count;
}

int main() {
    int n;
    int a[1005];
    int i, j, temp;
    int digit1, digit2;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            digit1 = hitung_digit(a[j]);
            digit2 = hitung_digit(a[j + 1]);

            if (digit1 < digit2) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            } else if (digit1 == digit2) {
                if (a[j] > a[j + 1]) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}