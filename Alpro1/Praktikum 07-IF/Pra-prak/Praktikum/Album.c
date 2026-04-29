#include <stdio.h>
#include <stdlib.h>
#include "Album.h"

void CreateAlbum(Album *A, int capacity) {
    A->buffer = (ElType *)malloc(capacity * sizeof(ElType));
    A->capacity = capacity;
    A->nEff = 0;
}

void DeallocateAlbum(Album *A) {
    free(A->buffer);
    A->buffer = NULL;
    A->capacity = 0;
    A->nEff = 0;
}

boolean IsEmpty(Album A) {
    return A.nEff == 0;
}

boolean IsFull(Album A) {
    return A.nEff == A.capacity;
}

void ExpandAlbum(Album *A, int num) {
    A->capacity += num;
    A->buffer = (ElType *)realloc(A->buffer, A->capacity * sizeof(ElType));
}

void SplitAndSwap(Album *A, int pivot) {
    /* 
       pivot adalah indeks elemen terakhir dari potongan KIRI.
       Contoh: [1,2,3,4,5], pivot=1 -> kiri=[1,2], kanan=[3,4,5]
       Hasil  : [3,4,5,1,2]

       Caranya: reverse seluruh array, lalu reverse dua bagian terpisah.
       Teknik ini O(n) tanpa alokasi memori tambahan.

       Misal arr = [1,2,3,4,5], pivot=1
       leftLen  = pivot+1 = 2  -> indeks 0..1
       rightLen = nEff - leftLen = 3 -> indeks 2..4

       Setelah swap kita inginkan: [3,4,5,1,2]
       = right dulu, lalu left

       Reverse seluruh: [5,4,3,2,1]
       Reverse bagian kiri baru (panjang rightLen=3): [3,4,5,2,1]
       Reverse bagian kanan baru (panjang leftLen=2): [3,4,5,1,2] ✓
    */

    int leftLen  = pivot + 1;
    int rightLen = A->nEff - leftLen;
    int n = A->nEff;

    /* Helper lambda via inline reverse */
    /* Reverse [lo..hi] inklusif */
    #define REVERSE(arr, lo, hi) \
        do { \
            int _l = (lo), _r = (hi); \
            while (_l < _r) { \
                ElType _tmp = (arr)[_l]; \
                (arr)[_l] = (arr)[_r]; \
                (arr)[_r] = _tmp; \
                _l++; _r--; \
            } \
        } while(0)

    REVERSE(A->buffer, 0, n - 1);
    REVERSE(A->buffer, 0, rightLen - 1);
    REVERSE(A->buffer, rightLen, n - 1);

    #undef REVERSE
}

void InjectList(Album *A1, Album A2, int idx) {
    int needed = A1->nEff + A2.nEff;
    if (needed > A1->capacity) {
        ExpandAlbum(A1, needed - A1->capacity);
    }

    for (int i = A1->nEff - 1; i >= idx; i--) {
        A1->buffer[i + A2.nEff] = A1->buffer[i];
    }

    for (int i = 0; i < A2.nEff; i++) {
        A1->buffer[idx + i] = A2.buffer[i];
    }

    A1->nEff += A2.nEff;
}

void PrintAlbum(Album A) {
    for (int i = 0; i < A.nEff; i++) {
        printf("%d", A.buffer[i]);
    }
    printf("\n");
}