#include <stdio.h>
#include <string.h>
#include "optik.h"

/* ===================== KONSTRUKTOR ===================== */

void CreateLensa(Lensa *L, double fokus, char tipe[]) {
    
    if (fokus != 0.0) {
        L->f = fokus;
    } else {
       
        L->f = 1.0; 
    }
    
    strncpy(L->jenis, tipe, 9);
    L->jenis[9] = '\0';
}

void CreateBenda(Benda *B, double jarak, double tinggi) {
    if (jarak > 0) {
        B->s = jarak;
    } else {
        B->s = 1.0; 
    }
    
    if (tinggi > 0) {
        B->h = tinggi;
    } else {
        B->h = 1.0; 
    }
}

/* ===================== OPERASI OPTIK ===================== */

Bayangan HitungBayangan(Lensa L, Benda B) {
    Bayangan Bay;
    

    if (B.s == L.f) {
        Bay.s_aks = 0.0;
        Bay.M = 0.0;
        Bay.h_aks = 0.0;
        Bay.isNyata = false;
        Bay.isTegak = true;
        return Bay;
    }

    Bay.s_aks = (B.s * L.f) / (B.s - L.f);

   
    Bay.M = -(Bay.s_aks) / B.s;


    Bay.h_aks = Bay.M * B.h;

    Bay.isNyata = (Bay.s_aks > 0) ? true : false;
    Bay.isTegak = (Bay.M > 0) ? true : false;

    return Bay;
}

void VisualisasiBayangan(Bayangan Bay) {
    printf("Jarak Bayangan (s'): %.2f cm\n", Bay.s_aks);
    printf("Tinggi Bayangan (h'): %.2f cm\n", Bay.h_aks);
    printf("Perbesaran (M): %.2f x\n", Bay.M);
    
    printf("Sifat: ");
    if (Bay.isNyata) {
        printf("Nyata, ");
    } else {
        printf("Maya, ");
    }
    
    if (Bay.isTegak) {
        printf("Tegak\n");
    } else {
        printf("Terbalik\n");
    }
}