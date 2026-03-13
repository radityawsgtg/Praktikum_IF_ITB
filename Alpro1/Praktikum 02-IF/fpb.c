#include<stdio.h>
#include<stdbool.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int banyak_n;
    scanf("%d", &banyak_n);
    int nilai_n[banyak_n];
    for (int i = 0; i < banyak_n; i++) {
        scanf("%d", &nilai_n[i]);
    }

    int g = nilai_n[0];
    for (int i = 1; i < banyak_n; i++) {
        g = gcd(g, nilai_n[i]);
    }

    int total = 0;
    for (int i = 0; i < banyak_n; i++) {
        total += nilai_n[i] / g;
    }
    printf("%d\n", total);

    return 0;
}
    
    
    
    





