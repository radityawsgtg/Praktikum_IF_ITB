#include <stdio.h>

int main() {
    int N;
    int A[105];
    int i; 

    if (scanf("%d", &N) != 1) {
        return 1;
    }


    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    //
    for (i = N - 1; i >= 0; i--) {
        printf("%d", A[i]);
        
        if (i > 0) {
            printf(" ");
        }
    }
    
    printf("\n");

    return 0;
}