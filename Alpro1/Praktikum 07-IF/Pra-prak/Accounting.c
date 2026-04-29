#include<stdio.h>
#include<stdlib.h>
#include"Accounting.h"


void CreateJournal(Journal *l, int capacity){
    l->buffer = (Transaction *)malloc(capacity * sizeof(Transaction));
    l->capacity = capacity;
    l->nEff = 0;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity */

void DealokasiJournal(Journal *l){
    free(l->buffer);
    l->capacity=0;
    l->nEff=0;
}
/* I.S. l terdefinisi */
/* F.S. List l dikembalikan ke sistem, l.capacity=0, l.nEff=0 */

boolean IsEmpty(Journal l){
    return l.nEff == 0;
}
/* Mengirimkan true jika list l kosong, false jika tidak */

boolean IsFull(Journal l){
    return l.nEff == l.capacity;
}
/* Mengirimkan true jika list l penuh, false jika tidak */

void ExpandJournal(Journal *l){
    l->capacity = l->capacity * 2;
    l->buffer = (Transaction *) realloc(l->buffer, l->capacity * sizeof(Transaction));
}
/* Meningkatkan kapasitas list sebesar dua kali lipat */

void InsertLastTrx(Journal *l, Transaction val){
    if (l->nEff * 100 / l->capacity >= 75)
    {
        ExpandJournal(l);
    }
    l->buffer[l->nEff] = val;
    l->nEff++;
}
/* Memasukkan Transaction val ke ujung akhir list */
/* Sebelum insert, jika list sudah lebih dari atau sama dengan 75% penuh,
   maka kapasitas list digandakan secara otomatis */

void CloneJournal(Journal lIn, Journal *lOut){
    CreateJournal(lOut, lIn.nEff); 
    lOut->nEff = lIn.nEff;
    for (int i = 0; i < lIn.nEff; i++){
        lOut->buffer[i] = lIn.buffer[i];
    }
}
/* Menyalin seluruh isi lIn ke lOut di alamat memori berbeda.
   Kapasitas lOut disesuaikan tepat sebesar nEff dari lIn. */

long long GetCompanyBalance(Journal l, int idCompany){
    long long balance = 0;
    for (int i = 0; i < l.nEff; i++){
        if (l.buffer[i].idCompany == idCompany){
            balance += l.buffer[i].debit - l.buffer[i].kredit;
        }
    }
    return balance;
}
/* Mengembalikan total saldo (Total Debit - Total Kredit)
   khusus untuk idCompany tertentu di dalam List. */
/* Keluarkan 0 jika company tidak valid */

void SortByTimestamp(Journal *l, boolean ascending) {
    for (int i = 0; i < l->nEff - 1; i++) {
        for (int j = 0; j < l->nEff - i - 1; j++) {
            boolean shouldSwap = false;
            
            if (ascending) {
                if (l->buffer[j].timestamp > l->buffer[j+1].timestamp) shouldSwap = true;
            } else {
                if (l->buffer[j].timestamp < l->buffer[j+1].timestamp) shouldSwap = true;
            }
            
            if (shouldSwap) {
                Transaction temp = l->buffer[j];
                l->buffer[j] = l->buffer[j+1];
                l->buffer[j+1] = temp;
            }
        }
    }
}
/* Mengurutkan elemen berdasarkan timestamp */
/* Algoritma sorting bebas */

void MergeJournal(Journal l1, Journal l2, Journal *lOut){
    int totalNEff = l1.nEff + l2.nEff;
    CreateJournal(lOut, totalNEff);
    for (int i = 0; i < l1.nEff; i++)
        lOut->buffer[i] = l1.buffer[i];
    for (int i = 0; i < l2.nEff; i++)
        lOut->buffer[l1.nEff + i] = l2.buffer[i];
    lOut->nEff = totalNEff;
    SortByTimestamp(lOut, true);
}
/* Menggabungkan dua list tidak terurut l1 dan l2
   ke list lOut yang terurut dengan timestamp menaik */

void PrintJournal(Journal l) {
    printf("Capacity: %d | nEff: %d\n", l.capacity, l.nEff);
    
    if (IsEmpty(l)) {
        printf("LIST KOSONG\n");
    } else {
        for (int i = 0; i < l.nEff; i++) {
            printf("[%d] TrxID: %d | CompID: %d | TS: %d | D: %lld | K: %lld\n",
                   i + 1, 
                   l.buffer[i].idTrx, 
                   l.buffer[i].idCompany, 
                   l.buffer[i].timestamp, 
                   l.buffer[i].debit, 
                   l.buffer[i].kredit);
        }
    }
}
/* Print list saat ini dengan format:
    Capacity: <capacity> | nEff: <nEff>
diikuti dengan:
    [1] TrxID: <idTrx> | CompID: <idCompany> | TS: <timestamp> | D: <debit> | K: <kredit>
    ...
    [N] TrxID: <idTrx> | CompID: <idCompany> | TS: <timestamp> | D: <debit> | K: <kredit>
jika list berisi, atau:
    LIST KOSONG
jika list kosong.

Semua baris diakhiri newline.
*/
