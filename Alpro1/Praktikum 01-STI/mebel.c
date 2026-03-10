#include <stdio.h>

int main() {
    int input;
    printf("Masukkan angka: ");
    if (scanf("%d", &input) != 1) return 1; 

    int lebar = (2 * input) - 1;

    for (int i = 0; i < input; i++) {
        for (int j = 0; j < lebar; j++) {
            
            if (j == 0 ||                  // Sisi kiri
                j == lebar - 1 ||          // Sisi kanan
                j == i ||                  // Diagonal kiri ke tengah
                j == (lebar - 1) - i)      // Diagonal kanan ke tengah
            {
                printf("M");
            } 
            else {
                printf("-"); //Sepasi saya ganti dash agar pebih mudah visualisasinya, tinggal ubah ke sepasi saja
            }
        }
        printf("\n"); 
    }

    return 0;
}