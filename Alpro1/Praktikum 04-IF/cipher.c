#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

int main() {
    init();
    
    char decrypt_map[256] = {0}; 
    char plain, cipher;

    FILE *file_kunci = fopen("kunci.txt", "r");
    if (file_kunci == NULL) {
        printf("Gagal membuka file kunci.txt\n");
        return 1;
    }

    while (fscanf(file_kunci, " %c", &plain) == 1 && plain != '.') {
        fscanf(file_kunci, " %c", &cipher);
        decrypt_map[(unsigned char)cipher] = plain;
    }
    fclose(file_kunci);

    FILE *file_cipher = fopen("ciphertext.txt", "r");
    if (file_cipher == NULL) {
        printf("Gagal membuka file ciphertext.txt\n");
        return 1;
    }

    char ch;
    while (fscanf(file_cipher, "%c", &ch) == 1) {
        if (ch == '.') {
            break;
        } else if (ch >= 'a' && ch <= 'z') {
            printf("%c", decrypt_map[(unsigned char)ch]);
        } else if (ch == ' ') {
            printf(" ");
        }
    }
    fclose(file_cipher);

    printf("\n");

    return 0;
}