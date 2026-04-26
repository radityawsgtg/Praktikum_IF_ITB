#include<stdio.h>
#include"Cursor.h"

/*#define MAX_LENGTH 100

typedef struct {
    char TextInput[MAX_LENGTH];
    int CursorPos; // Posisi kursor yang valid: 0-TextLen
    int TextLen;
} Cursor;
*/

void InitCursor (Cursor *C){
    C->CursorPos=0;
}
/* Membuat struct Cursor baru dengan posisi cursor di awal (0) dan belum ada teks apapun pada input */

void MoveLeft (Cursor *C, int step){
    C->CursorPos = step;
}
/* Menggeser posisi cursor ke kiri sejauh step atau sampai berada sebelum karakter pertama text input */

void MoveRight (Cursor *C, int step){
    C->CursorPos += step;
    if (C->CursorPos > C->TextLen) {
        C->CursorPos = C->TextLen;
    }
}
/* Menggeser posisi cursor ke kanan sejauh step atau sampai melewati karakter terakhir text input */

void Type (Cursor *C, char input){
    /* Menerima karakter input dan menambahkannya di posisi cursor saat ini
    Setelah menambahkan karakter, posisi cursor akan bergeser selangkah ke kanan */
    for (int i = C->TextLen; i > C->CursorPos; i--) {
        C->TextInput[i] = C->TextInput[i - 1];
    }
    C->TextInput[C->CursorPos] = input;
    C->TextLen++;
    C->CursorPos++;
}

void Backspace (Cursor *C){
    /* Menghapus satu karakter di kiri posisi cursor saat ini 
    dan menggeser posisi cursor selangkah ke kiri */
    if (C->CursorPos > 0) {
        for (int i = C->CursorPos - 1; i < C->TextLen - 1; i++) {
            C->TextInput[i] = C->TextInput[i + 1];
        }
        C->TextLen--;
        C->CursorPos--;
    }
}

void Home (Cursor *C){
    /* Memindahkan posisi kursor ke paling awal (sebelum karakter pertama) */
    C->CursorPos = 0;
}

void End (Cursor *C){
    /* Memindahkan posisi kursor ke paling akhir (setelah karakter terakhir) */
    C->CursorPos = C->TextLen;
}

void Print (Cursor C){
    printf("Mati");
}
/* Mencetak isi dari text input saat ini yang disertai dengan posisi kursor (dilambangkan |), formatnya:
Misal, text input = "halo", posisi kursor = 1, maka cetak:
h|alo
Jangan lupa akhiri dengan newline ("\n") */