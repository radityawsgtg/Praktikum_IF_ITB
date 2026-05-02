#include "dna.h"
#include "boolean.h"
#include <string.h>

/* ***************************************************************** */
/* KONSTRUKTOR                                                       */
/* ***************************************************************** */

void CreateDNA(DNA *D, char seq[]) {
    strncpy(D->rantai, seq, MAX_LEN - 1);
    D->rantai[MAX_LEN - 1] = '\0';
    D->panjang = strlen(D->rantai);
}

/* ***************************************************************** */
/* SELEKTOR / PREDIKAT                                               */
/* ***************************************************************** */

boolean IsStartCodon(DNA D, int idx) {
    if (idx < 0 || idx > D.panjang - 3) {
        return false;
    }
    if (D.rantai[idx] == 'A' && D.rantai[idx+1] == 'T' && D.rantai[idx+2] == 'G') {
        return true;
    }
    return false;
}

boolean IsStopCodon(DNA D, int idx) {
    if (idx < 0 || idx > D.panjang - 3) {
        return false;
    }
    if (D.rantai[idx] == 'T') {
        if (D.rantai[idx+1] == 'A' && D.rantai[idx+2] == 'A') return true; // TAA
        if (D.rantai[idx+1] == 'A' && D.rantai[idx+2] == 'G') return true; // TAG
        if (D.rantai[idx+1] == 'G' && D.rantai[idx+2] == 'A') return true; // TGA
    }
    return false;
}

/* ***************************************************************** */
/* OPERASI UTAMA                                                     */
/* ***************************************************************** */

DNA EkstrakProtein(DNA D) {
    DNA hasil;
    CreateDNA(&hasil, ""); 
    for (int i = 0; i <= D.panjang - 3; i++) {
        if (IsStartCodon(D, i)) {
            
            for (int j = i + 3; j <= D.panjang - 3; j += 3) {
                if (IsStopCodon(D, j)) {
                    int panjang_orf = (j + 3) - i; 
                    
                    strncpy(hasil.rantai, &D.rantai[i], panjang_orf);
                    hasil.rantai[panjang_orf] = '\0';
                    hasil.panjang = panjang_orf;
                    
                    return hasil; 
                }
            }
        }
    }
    
    return hasil;
}