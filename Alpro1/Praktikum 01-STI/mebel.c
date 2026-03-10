#include <stdio.h>

int main() {
    int input;
    printf("Masukkan angka: ");
    // Gunakan &input untuk menangkap alamat memori
    if (scanf("%d", &input) != 1) return 1; 

    int lebar = (2 * input) - 1;

    for (int i = 0; i < input; i++) {
        for (int j = 0; j < lebar; j++) {
            // Syarat mencetak 'M'
            if (j == 0 ||                  // Sisi kiri
                j == lebar - 1 ||          // Sisi kanan
                j == i ||                  // Diagonal kiri ke tengah
                j == (lebar - 1) - i)      // Diagonal kanan ke tengah
            {
                printf("M");
            } 
            else {
                printf("-");
            }
        }
        printf("\n"); // Pindah baris setelah satu baris selesai
    }

    return 0;
}