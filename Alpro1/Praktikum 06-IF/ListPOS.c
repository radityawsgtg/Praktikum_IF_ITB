#include<stdio.h>
#include"ListPOS.h"
/*
#define CAPACITY 20
#define IDX_UNDEF -1


typedef struct {
    int idPesanan;   
    int waktuMasuk;  
    int totalItem;
    int hargaPerItem;
} Pesanan;

typedef struct {
    Pesanan buffer[CAPACITY];
    int neff;
} ListPOS;

*/

/* Konstruktor : create list POS kosong */
void CreateListPOS(ListPOS *l){
    l->neff= 0;
}

/* Mengecek list kosong
 * Mengirimkan true jika list kosong, mengirimkan false jika tidak */
boolean IsEmpty(ListPOS l){
    if (l.neff == 0)
    {
        return true;
    }
    return false;
    
}

/* Mengecek list penuh */
/* Mengirimkan true jika list penuh, mengirimkan false jika tidak */
boolean IsFull(ListPOS l){
    if (l.neff < CAPACITY)
    {
        return false;
    }
    return true;
}

/* Mencari indeks Pesanan berdasarkan idPesanan */
/* Kembalikan IDX_UNDEF jika tidak ditemukan */
int CariIndeksPesanan(ListPOS l, int idPesanan){
    for (int i = 0; i < l.neff; i++)
    {
        if (l.buffer[i].idPesanan == idPesanan)
        {
            return i;
        }
    }
    return IDX_UNDEF;
}

/* Menambahkan pesanan ke akhir list (insert last) */
/* Jika list penuh, print "GAGAL MENAMBAHKAN" diakhiri dengan newline  */
void TambahPesanan(ListPOS *l, Pesanan p){
    if (IsFull(*l))
    {
        printf("GAGAL MENAMBAHKAN\n");
        return;
    }
    l->buffer[l->neff] = p;
    l->neff++;
}

/* Menghapus pesanan dengan waktuMasuk paling awal, kemudian geser semua pesanan di kanannya ke kiri */
/* Jika berhasil menyelesaikan pesanan, kembalikan nilai true dan simpan pesanan ke variabel pointer *p */
/* Jika tidak ada pesanan yang bisa diselesaikan, print "GAGAL MENYELESAIKAN" diakhiri dengan newline, dan kembalikan nilai false */
boolean SelesaikanPesanan(ListPOS *l, Pesanan *p){
    if (l->neff == 0)
    {
        printf("GAGAL MENYELESAIKAN\n");
        return false;
    }
    
    *p = l->buffer[0];
    for (int i = 1; i < l->neff; i++)
    {
        l->buffer[i-1] = l->buffer[i];
    }
    l->neff--;
    return true;
}

/* Menghapus pesanan sesuai idPesanan, kemudian geser semua pesanan di kanannya ke kiri */
/* Jika tidak ada pesanan yang bisa dibatalkan, print "GAGAL MEMBATALKAN" diakhiri dengan newline */
void BatalkanPesanan(ListPOS *l, int idPesanan){
    if (l->neff == 0)
    {
        printf("GAGAL MEMBATALKAN\n");
        return;
    }
    for (int i = CariIndeksPesanan(*l,idPesanan); i < l->neff; i++)
    {
        l->buffer[i] = l->buffer[i+1];
    }
    l->neff--;
}

/* Mengembalikan jumlah harga total pesanan dengan id idPesanan */
/* Kembalikan 0 jika pesanan tidak ada */
int HitungHargaTotalPesanan(ListPOS l, int idPesanan){
    for (int i = 0; i < l.neff; i++)
    {
        if (l.buffer[i].idPesanan == idPesanan)
        {
            return l.buffer[i].hargaPerItem * l.buffer[i].totalItem;
        }
    }
    return 0;
}

/* Mengembalikan jumlah item total seluruh pesanan di list */
int HitungSemuaItem(ListPOS l){
    int total = 0;
    for (int i = 0; i < l.neff; i++)
    {
        total += l.buffer[i].totalItem;
    }
    return total;
}

/* Mengembalikan jumlah harga total seluruh pesanan di list */
int HitungSemuaHargaTotal(ListPOS l){
    int total = 0;
    for (int i = 0; i < l.neff; i++)
    {
        total += (l.buffer[i].hargaPerItem) * (l.buffer[i].totalItem);
    }
    return total;
}

/* Mencetak pesanan ke layar dengan format:

   {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>

   Pastikan diakhiri dengan newline */
void CetakPesanan(Pesanan p){
    printf("{%d - %d}: %d x %d = %d\n", p.idPesanan, p.waktuMasuk, p.hargaPerItem, p.totalItem, p.hargaPerItem * p.totalItem);
}


/* Mencetak semua pesanan di list ke layar dengan format:

   [1] {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>
   [2] {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>
   ...
   [N] {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>

   Pastikan setiap baris diakhiri dengan newline */
void CetakSemuaPesanan(ListPOS l){
    for (int i = 0; i < l.neff; i++)
    {
        printf("[%d] ", i+1);
        CetakPesanan(l.buffer[i]);
    }
}
