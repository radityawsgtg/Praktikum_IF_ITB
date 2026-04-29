#include<stdio.h>
#include<stdlib.h>
#include"Level.h"



void CreateLevel(Level *L, int capacity){
    /* mau gw usilin tapi ada jevon gw ga enak golbog bgt dah lu bego mati mati YOU VS JEVOB lolo sotpid , wait yak gw prak dulu ^^bodo amag.*/
    L->listOfBlocks = (Block *)malloc(capacity * sizeof(Block));
    L->capacity = capacity;
    L->nEff = 0;
}
/* I.S. L sembarang, capacity > 0 */
/* F.S. Terbentuk Level L kosong dengan kapasitas capacity */

void DealocateLevel(Level *L){
    free(L->listOfBlocks);
    L->capacity = 0;
    L->nEff =0;
}
/* I.S. L terdefinisi */
/* F.S. L.listOfBlocks dikembalikan ke sistem, L.capacity = 0, L.nEff = 0 */

boolean IsEmpty(Level L){
    return L.nEff == 0;
}
/* Mengirimkan true jika level kosong, false jika tidak */

boolean IsFull(Level L){
    return L.nEff == L.capacity;
}
/* Mengirimkan true jika level penuh, false jika tidak */

void ExpandLevel(Level *L, int num){
    L->capacity += num;
    L->listOfBlocks = (Block *)realloc(L->listOfBlocks, L->capacity * sizeof(Block));
}
/* Proses: Menambahkan capacity L sebanyak num */
/* I.S. L sudah terdefinisi, num > 0 */
/* F.S. Ukuran capacity bertambah sebanyak num */

void AddBlock(Level *L, int height, boolean isTrap){
    if (height < 0 || height > MAX_HEIGHT) return;
    if (IsFull(*L))
    {
        ExpandLevel(L,EXPAND_LEN);
    }
    L->listOfBlocks[L->nEff].height = height;
    L->listOfBlocks[L->nEff].isTrap = isTrap;
    L->nEff++;
    
}
/* Proses: Menambahkan block baru di akhir level. Jika list penuh, expand kapasitasnya sebesar EXPAND_LEN sebelum diisi. */
/* I.S. L terdefinisi, height >= 0 */
/* F.S. Block baru ditambahkan sebagai elemen terakhir L */
/* Pastikan block valid. Jika block tidak valid, block tidak ditambahkan */

void RemoveLastBlock(Level *L){
    if (!IsEmpty(*L))
    {
        L->nEff--;
    }
    
}
/* Proses: Menghapus block terakhir pada level */
/* I.S. L terdefinisi */
/* F.S. Block di akhir L hilang */

boolean IsJumpValid(Level L, int currentIdx, int targetIdx) {
    if (targetIdx <= currentIdx) return false;
 
    int horizDist = targetIdx - currentIdx;
    if (horizDist > 2) return false;
 
    int currentHeight = L.listOfBlocks[currentIdx].height;
    int targetHeight  = L.listOfBlocks[targetIdx].height;
    int vertDiff = targetHeight - currentHeight; 
    if (vertDiff > 1) return false;
 
    if (vertDiff < -3) return false;
 
    if (L.listOfBlocks[targetIdx].isTrap) return false;
 
    return true;
}

 
boolean IsLevelBeatable(Level L) {
    if (IsEmpty(L)) return false;
    if (L.nEff == 1) return true;
 

    boolean *reachable = (boolean *)malloc(L.nEff * sizeof(boolean));
 
    for (int i = 0; i < L.nEff; i++) reachable[i] = false;
    reachable[0] = true; 
 
    for (int i = 0; i < L.nEff; i++) {
        if (!reachable[i]) continue;
        for (int step = 1; step <= 2; step++) {
            int target = i + step;
            if (target >= L.nEff) break;
            if (IsJumpValid(L, i, target)) {
                reachable[target] = true;
            }
        }
    }
 
    boolean result = reachable[L.nEff - 1];
    free(reachable);
    return result;
}
 
void PrintLevel(Level L) {
    if (IsEmpty(L)) return;
 
    int maxHeight = 0;
    for (int i = 0; i < L.nEff; i++) {
        if (L.listOfBlocks[i].height > maxHeight) {
            maxHeight = L.listOfBlocks[i].height;
        }
    }
 
    for (int h = maxHeight; h >= 0; h--) {
        boolean hasBlock = false;
        for (int i = 0; i < L.nEff; i++) {
            if (L.listOfBlocks[i].height == h) {
                hasBlock = true;
                break;
            }
        }
        if (!hasBlock) continue;
 
        printf("Height = %d: ", h);
        for (int i = 0; i < L.nEff; i++) {
            if (L.listOfBlocks[i].height == h) {
                if (L.listOfBlocks[i].isTrap) {
                    printf("[T]");
                } else {
                    printf("[B]");
                }
            } else {
                printf("[]");
            }
        }
        printf("\n");
    }
}