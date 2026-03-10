#include <stdio.h>

int main() {
    int n, b;
    int sisa[64];
    int i = 0;

    if (scanf("%d %d", &n, &b) != 2) return 1; 

    if (n < 0 || b < 2 || b > 9) {
        printf("Masukan tidak valid\n");
        return 0; 
    }

    if (n == 0) {
        printf("Masukan tidak valid\n");
        return 0;
    }

    int temp_n = n;
    while (temp_n > 0) {
        sisa[i] = temp_n % b;
        temp_n = temp_n / b;
        i++; 
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", sisa[j]);
    }
    printf("\n");

    return 0;
}