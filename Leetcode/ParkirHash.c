#include<stdio.h>
#include <stdbool.h>
#include"ParkirHash.h"

//define CAPACITY 100 

/*
typedef struct {
    int platNomor;
    bool isKosong; // Penanda apakah elemen ini kosong atau ada mobilnya
} Kendaraan; */

/*
typedef struct {
    Kendaraan slot[CAPACITY]; // List statis penyimpan kendaraan
    int M; // Batas jumlah slot yang dipakai (sesuai input)
} AreaParkir;*/

// --- Deklarasi Fungsi Dasar (Primitif ADT) ---

// Fungsi untuk mengeset semua slot di AreaParkir menjadi KOSONG
void CreateParkir(AreaParkir *P, int ukuran){
    P->M = ukuran;
    for (int i = 0; i < P->M; i++)
    {
        P->slot[i].isKosong = true;
    }
}

// Fungsi untuk memasukkan plat nomor ke dalam AreaParkir dengan logika Hash & Linear Probing
void InsertKendaraan(AreaParkir *P, int plat){
    int idx = plat % P->M;
    int count  = 0;
    for (int i = 0; i < P->M; i++)
    {
        if (P->slot[i].isKosong == false)
        {
            count++;
        }
        
    }
    
    while (P->slot[idx].isKosong == false && count != P->M)
    {
        idx = (idx+1)%P->M;
    }

    if (count != P->M) { 
        P->slot[idx].platNomor = plat;
        P->slot[idx].isKosong = false;
    } else {
        printf("Parkiran penuh! Plat %d tidak bisa masuk.\n", plat);
    }
}

// Fungsi untuk mencetak AreaParkir ke layar
void PrintParkir(AreaParkir P){
    for (int i = 0; i < P.M; i++)
    {
        if (P.slot[i].isKosong == true)
        {
            printf("Slot %d : KOSONG\n", i);
        }
        else{
            printf("Slot %d : plat %d\n", i, P.slot[i].platNomor);
        }
        
    }
    
}

int main() {
    AreaParkir P;
    int M, N;
    
    // 1. Baca ukuran parkiran (M) dan jumlah mobil (N)
    // Contoh input di terminal nanti: 5 4
    scanf("%d %d", &M, &N);
    
    // 2. Inisialisasi parkiran
    CreateParkir(&P, M);
    
    // 3. Looping untuk membaca N buah plat nomor mobil
    for (int i = 0; i < N; i++) {
        int plat;
        scanf("%d", &plat);          // Baca plat nomor (contoh: 12)
        InsertKendaraan(&P, plat);   // Masukkan ke dalam Hash Table (parkiran)
    }
    
    // 4. Cetak hasil akhir
    PrintParkir(P);
    
    return 0; // Program selesai
}
