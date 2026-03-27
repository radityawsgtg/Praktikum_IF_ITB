#include <stdio.h>

int main() {
    int n;
    int a[105];
    int i, j;
    
  
    long long total = 0;

    // Membaca input n
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    // Membaca elemen array
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {

        for (j = i + 1; j < n; j++) {
            
            int min_val;
            if (a[i] < a[j]) {
                min_val = a[i];
            } else {
                min_val = a[j];
            }
            
            total += min_val;
        }
    }
    
    printf("%lld\n", total);
    
    return 0;
}