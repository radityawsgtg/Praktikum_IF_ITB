#include <stdio.h>
#include <stdlib.h>

// Fungsi twoSum tetap sama seperti sebelumnya
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

int main() {
    int n, target, ukuranHasil;

    // 1. Tanya jumlah angka
    printf("Masukkan jumlah angka dalam kumpulan: ");
    scanf("%d", &n);

    // 2. Buat array sesuai jumlah n
    int nums[n]; 
    printf("Masukkan %d angka (pisahkan dengan spasi/enter):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Masukkan target jumlah: ");
    scanf("%d", &target);

    int* hasil = twoSum(nums, n, target, &ukuranHasil);

    if (hasil != NULL) {
        printf("Hasil ditemukan pada index: [%d, %d]\n", hasil[0], hasil[1]);
        printf("Angkanya adalah: %d + %d = %d\n", nums[hasil[0]], nums[hasil[1]], target);
        free(hasil); 
    } else {
        printf("Tidak ada pasangan angka yang jumlahnya %d\n", target);
    }

    return 0;
}