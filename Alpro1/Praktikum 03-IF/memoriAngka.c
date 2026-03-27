#include <stdio.h>
#include <stdbool.h>

bool pernahMuncul[100005]; 

int main() {
    int N;
    
    if (scanf("%d", &N) != 1) {
        return 1; 
    }

    for (int i = 0; i < N; i++) {
        int angka;
        scanf("%d", &angka);

        if (pernahMuncul[angka] == false) {
            printf("BARU\n");
            pernahMuncul[angka] = true; 
        } else {
            printf("LAMA\n");
        }
    }

    return 0;
}