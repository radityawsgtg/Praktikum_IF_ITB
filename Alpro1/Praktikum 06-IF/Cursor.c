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
    C->CursorPos = 0;
    C->TextLen = 0;

}
/* Membuat struct Cursor baru dengan posisi cursor di awal (0) dan belum ada teks apapun pada input */

void MoveLeft (Cursor *C, int step){
    C->CursorPos = C->CursorPos - step;
    if (C->CursorPos < 0)
    {
        C->CursorPos = 0;
    }
    
}
/* Menggeser posisi cursor ke kiri sejauh step atau sampai berada sebelum karakter pertama text input */

void MoveRight (Cursor *C, int step){
    C->CursorPos= C->CursorPos+ step;
    if (C->CursorPos > C->TextLen)
    {
        C->CursorPos = C->TextLen;
    }
    
}
/* Menggeser posisi cursor ke kanan sejauh step atau sampai melewati karakter terakhir text input */

void Type (Cursor *C, char input){
    if (C->TextLen < MAX_LENGTH -1)
    {
        for (int i = C->TextLen; i > C->CursorPos ; i--)
        {
            C->TextInput[i]= C->TextInput[i-1];
        }
        C->TextInput[C->CursorPos] = input;
        C->TextLen++;
        C->CursorPos++;
        C->TextInput[C->TextLen] = '\0';
    }
    
    
}
/* Menerima karakter input dan menambahkannya di posisi cursor saat ini
Setelah menambahkan karakter, posisi cursor akan bergeser selangkah ke kanan */

void Backspace (Cursor *C){
    if (C->CursorPos > 0)
    {
        for (int i = C->CursorPos; i < C->TextLen-1; i++)
        {
            C->TextInput[i-1] = C->TextInput[i];
        }
        C->TextLen--;
        C->CursorPos--;
        C->TextInput[C->TextLen] = '\0';

    }
    
}
/* Menghapus satu karakter di kiri posisi cursor saat ini 
dan menggeser posisi cursor selangkah ke kiri */

void Home (Cursor *C){
    C->CursorPos = 0;
}
/* Memindahkan posisi kursor ke paling awal (sebelum karakter pertama) */

void End (Cursor *C){
    C->CursorPos = C->TextLen;
}
/* Memindahkan posisi kursor ke paling akhir (setelah karakter terakhir) */

void Print (Cursor C){
    for (int i = 0; i <= C.TextLen; i++)
    {
        if (i == C.CursorPos)
        {
            printf("|");
        }
        if (i < C.TextLen)
        {
            printf("%c", C.TextInput[i]);
        }
        
    }
    printf("\n");
}
/* Mencetak isi dari text input saat ini yang disertai dengan posisi kursor (dilambangkan |), formatnya:
Misal, text input = "halo", posisi kursor = 1, maka cetak:
h|alo
Jangan lupa akhiri dengan newline ("\n") */
int main() {
    Cursor C;

    printf("--- Test 1: Inisialisasi ---\n");
    InitCursor(&C);
    Print(C); 
    // Ekspektasi Output: |

    printf("\n--- Test 2: Mengetik (Type) ---\n");
    Type(&C, 'H');
    Type(&C, 'a');
    Type(&C, 'l');
    Type(&C, 'o');
    Print(C); 
    // Ekspektasi Output: Halo|

    printf("\n--- Test 3: Geser Kiri & Ketik di Tengah ---\n");
    MoveLeft(&C, 2);
    Print(C); 
    // Ekspektasi Output: Ha|lo
    Type(&C, 's');
    Print(C); 
    // Ekspektasi Output: Has|lo

    printf("\n--- Test 4: Backspace di Tengah ---\n");
    Backspace(&C);
    Print(C); 
    // Ekspektasi Output: Ha|lo

    printf("\n--- Test 5: Lompat ke Home & Ketik ---\n");
    Home(&C);
    Print(C); 
    // Ekspektasi Output: |Halo
    Type(&C, 'A');
    Print(C); 
    // Ekspektasi Output: A|Halo

    printf("\n--- Test 6: Lompat ke End & Backspace ---\n");
    End(&C);
    Print(C); 
    // Ekspektasi Output: AHalo|
    Backspace(&C);
    Print(C); 
    // Ekspektasi Output: AHal|

    printf("\n--- Test 7: Uji Kebablasan (Edge Cases) ---\n");
    MoveRight(&C, 100); // Sengaja digeser ke kanan jauh banget
    Print(C); 
    // Ekspektasi Output: AHal| (Kursor tidak boleh tembus batas)
    
    MoveLeft(&C, 100); // Sengaja digeser ke kiri jauh banget
    Print(C); 
    // Ekspektasi Output: |AHal (Kursor mentok di nol)
    
    Backspace(&C); // Sengaja hapus saat kursor di ujung kiri
    Print(C); 
    // Ekspektasi Output: |AHal (Program tidak boleh error/crash)

    printf("\n--- Semua Test Selesai! ---\n");
    return 0;
}