#include <stdio.h>

long long kombinasi(int a, int b) { 
    long long temp_a = 1;
    long long temp_b = 1;
    
    // 7 C 3 = 7 6 5 / 1 2 3
    // 6 C 4 = 6 5 4 3 / 1 2 3 4
    for (int j = a; j >= (a - b + 1); j--) {
        temp_a = temp_a * j;
    }
    for (int i = 1; i <= b; i++) {
        temp_b = temp_b * i;
    }
    
    return temp_a / temp_b;
}

long long catalan(int n) {
    long long hasil_kombinasi = kombinasi(2 * n, n);
    return hasil_kombinasi / (n + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld",catalan(n));
    return 0;
}

// KOMEN TEMPLATE COMBIN
// for (int i )