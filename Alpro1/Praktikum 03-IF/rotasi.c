#include <stdio.h>

int main() {
    int N, Q, K;
    int A[105];
    char C;
    int i;
    int start = 0; 

   
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Membaca jumlah operasi Q
    scanf("%d", &Q);

    for (i = 0; i < Q; i++) {
        scanf(" %c %d", &C, &K);
        
        K = K % N;
        
        if (C == 'L') {
            start = (start + K) % N;
        } else if (C == 'R') {
            start = (start - K + N) % N;
        }
    }

    for (i = 0; i < N; i++) {
        printf("%d", A[(start + i) % N]);
        
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}