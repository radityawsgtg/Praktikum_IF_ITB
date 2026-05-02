// --- AWAL HEADER GUARD ---
#ifndef PARKIRHASH_H
#define PARKIRHASH_H

#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 100 // Ukuran maksimal list statis

// 1. Mendefinisikan tipe bentukan (struct) untuk Kendaraan
typedef struct {
    int platNomor;
    bool isKosong; // Penanda apakah elemen ini kosong atau ada mobilnya
} Kendaraan;

// 2. Mendefinisikan ADT AreaParkir yang menggunakan List Statis (Array)
typedef struct {
    Kendaraan slot[CAPACITY]; // List statis penyimpan kendaraan
    int M; // Batas jumlah slot yang dipakai (sesuai input)
} AreaParkir;

// --- Deklarasi Fungsi Dasar (Primitif ADT) ---

// Fungsi untuk mengeset semua slot di AreaParkir menjadi KOSONG
void CreateParkir(AreaParkir *P, int ukuran);

// Fungsi untuk memasukkan plat nomor ke dalam AreaParkir dengan logika Hash & Linear Probing
void InsertKendaraan(AreaParkir *P, int plat);

// Fungsi untuk mencetak AreaParkir ke layar
void PrintParkir(AreaParkir P);

// --- AKHIR HEADER GUARD ---
#endif