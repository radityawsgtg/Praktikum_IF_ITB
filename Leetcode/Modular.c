#include <stdio.h>


#define CAPACITY 100 // Maksimal kombinasi yang bisa disimpan
/*Persamaan 21x + 15y = C*/

// 1. Tipe bentukan untuk satu pasang (x, y)
typedef struct {
    int pelacak;  // Nilai x
    int mikrofon; // Nilai y
} Transaksi;

// 2. Tipe bentukan List Statis untuk menyimpan daftar transaksi
typedef struct {
    Transaksi data[CAPACITY]; // Array of struct
    int jumlahKombinasi;      // Berapa banyak kombinasi yang valid
} ListTransaksi;

// --- Deklarasi Fungsi ---

// Inisialisasi list (set jumlahKombinasi jadi 0)
void CreateList(ListTransaksi *L){
    L->jumlahKombinasi = 0 ;
}

// Tambah kombinasi (x, y) ke dalam list
void TambahKombinasi(ListTransaksi *L, int x, int y){
    L->data[L->jumlahKombinasi].pelacak = x;
    L->data[L->jumlahKombinasi].mikrofon = y;  
}

// Proses pencarian solusi Diophantine
void AnalisisTransaksi(ListTransaksi *L, int totalKoin){
    int C = totalKoin;
    int max_attempt_x = C /21;
    for (int i = 1; i <= max_attempt_x; i++)
    {
        if ((totalKoin - (i*21))%15 == 0)
        {
            L->data[L->jumlahKombinasi].mikrofon = ((totalKoin - (i*21))/15);
            L->data[L->jumlahKombinasi].pelacak = i;
            L->jumlahKombinasi++;
        }
        
    }
    
}

// Cetak hasil dari list ke layar
void PrintLaporan(ListTransaksi L){
    printf("Ditemukan sebanyak %d kombinasi :\n", L.jumlahKombinasi);
    for (int i = 0; i < L.jumlahKombinasi; i++)
    {
        printf("Kombinasi %d: %d Pelacak dan %d Mikrofon\n",i,L.data[i].pelacak,L.data[i].mikrofon);
    }
    

}

int main() {
    ListTransaksi L;
    int koin;
    printf("Masukan Jumlah koin dari bos:");
    scanf("%d", &koin);
    CreateList(&L);
    AnalisisTransaksi(&L,koin);
    PrintLaporan(L);
    
    // 1. Baca input
    // 2. Inisialisasi List
    // 3. Panggil fungsi AnalisisTransaksi
    // 4. Panggil fungsi PrintLaporan
    
    return 0;
}