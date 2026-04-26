#include <stdio.h>       // Untuk printAnomalies
#include "ListAnomali.h" // Wajib
#include "boolean.h"



/* Indeks yang digunakan [IDX_MIN..MAX_CAPACITY - 1] */
/* Jika T adalah ListAnomali, */
/* Maka cara akses:
 * T.nEff untuk mengetahui banyaknya elemen saat ini
 * T.buffer untuk mengakses seluruh nilai elemen list
 * T.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
 * list kosong: T.nEff = 0
 * list penuh: T.nEff = MAX_CAPACITY
 * Definisi elemen pertama : T.buffer[i] dengan i=IDX_MIN
 * Definisi elemen terakhir yang terdefinisi: T.buffer[i] dengan i=(T.nEff - 1)*/

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong */
void CreateListAnomali(ListAnomali *T){
    T->nEff = 0;
}
/* I.S. T sembarang */
/* F.S. Terbentuk list T kosong dengan kapasitas MAX_CAPACITY */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int countAnomaly(ListAnomali T){
    if (T.nEff > 0)
    {
        return T.nEff;
    }
        return 0;
    
}
/* Mengirimkan banyaknya anomali efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Daya tampung anomali list *** */
int maxNbAnomaly(ListAnomali T){
    return MAX_CAPACITY;

}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh list (MAX_CAPACITY) */

/* ********** Test Indeks yang valid ********** */
boolean isIdxEff(ListAnomali T, IdxType i){
    if (i >= IDX_MIN && i <T.nEff)
    {
        return true;
    }
    return false;
    
}
/* Prekondisi : List T sembarang (bisa kosong atau bisa terisi), i sembarang */
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list yaitu antara indeks pertama dan indeks nEff */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListAnomali T){
    if (T.nEff == 0)
    {
        return true;
    }
        return false;
    
}
/* Mengirimkan true jika list T kosong, mengirimkan false jika tidak */

/* *** Test list penuh *** */
boolean isFull(ListAnomali T){
    if (T.nEff == MAX_CAPACITY)
    {
        return true;
    }
        return false;
    
}
/* Mengirimkan true jika list T penuh, mengirimkan false jika tidak */

/* ********** Selektor INDEKS ********** */
IdxType getFirstIdx(ListAnomali T){
    if (isEmpty(T))
    {
        return IDX_UNDEF;
    }
    return IDX_MIN;
    
    
}
/* Prekondisi : List T sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan indeks elemen pertama yaitu IDX_MIN */
/* Jika list kosong, return IDX_UNDEF */

IdxType getLastIndex(ListAnomali T){
        if (isEmpty(T))
    {
        return IDX_UNDEF;
    }
    return T.nEff-1;

}
/* Prekondisi : List T sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan indeks elemen efektif terakhir */
/* Jika list kosong, return IDX_UNDEF */

/* *** Menghasilkan sebuah elemen *** */
ElType getAnomalyAtIdx(ListAnomali T, IdxType i){
    if (!isIdxEff(T,i))
    {
        return ELEM_UNDEF;
    }
    return T.buffer[i];
    

}
/* Prekondisi : list T sembarang (bisa kosong atau bisa terisi), i mungkin tidak valid*/
/* Mengirimkan elemen list yang ke-i */
/* Jika list kosong atau indeks tidak valid, return ELEM_UNDEF */

/* ********** INPUT/OUTPUT ********** */
void printAnomalies(ListAnomali T){
    if (isEmpty(T)) {
         printf("LIST KOSONG\n");
    } else { // Tambahkan else di sini
        printf("[");
        for (int i = 0; i < T.nEff; i++) {
            printf("%d", T.buffer[i]);
            if (i < T.nEff-1) {
                printf(",");
            }
        }
        printf("]\n");
    }
}
/* Prekondisi: T boleh kosong */
/* Menuliskan isi list dengan traversal */
/* Tampilkan list dalam kurung siku dalam bentuk [<Elemen-1>,<Elemen-2>,<Elemen-3>,..<Elemen-nEff>], seperti [1,2,3], dan diakhiri newline */
/* Perhatikan bahwa tidak ada spasi dalam output */
/* Jika T kosong : Hanya menulis "LIST KOSONG" dan diakhiri newline */

/* ********** Operasi Dasar ********** */
void setAt(ListAnomali *T, ElType v, IdxType i){
    if (isIdxEff(*T,i))
    {
        T->buffer[i] = v;
    }
    
}
/* Prekondisi : list T terisi, indeks i bisa tidak valid */
/* Mengganti elemen T pada indeks i menjadi v */

void insertAt(ListAnomali *T, ElType v, IdxType i){
        if (!isFull(*T) && i >= 0 && i <= T->nEff)
    {
        for (int j = T->nEff; j > i ; j--)
        {
            T->buffer[j] = T->buffer[j-1];
        }
            T->buffer[i] = v;
        T->nEff++;
    }
        
}
/* Prekondisi : list T sembarang (bisa kosong atau bisa terisi) dan TIDAK PENUH, indeks i bisa tidak valid */
/* Menyelipkan elemen v ke T di indeks i */
/* Semua elemen setelah indeks digeser ke kanan */

void deleteAt(ListAnomali *T, IdxType i, ElType *v){
    if (isIdxEff(*T, i)) {
        *v = T->buffer[i]; // PINDAHKAN KE SINI! Ambil sebelum ditimpa

        for (int j = i; j < T->nEff-1; j++) {
            T->buffer[j] = T->buffer[j+1];
        }
        T->nEff--;
    }
}
/* Prekondisi : list T sembarang (bisa kosong atau bisa terisi) dan indeks i bisa tidak valid */
/* Menghapus ElType pada indeks i */
/* Semua elemen setelahnya DIGESER ke kiri */
/* Elemen yang dihapus disimpan pada v */

/* ********** Anomaly Operations ********** */
ElType highestAnomaly(ListAnomali T) {
    // 1. Anggap elemen pertama adalah yang terbesar untuk saat ini
    ElType max = T.buffer[0];

    // 2. Cukup pakai SATU perulangan (mulai dari indeks 1 sampai terakhir)
    for (int i = 1; i < T.nEff; i++) {
        // 3. Jika ketemu yang lebih besar dari 'max'
        if (T.buffer[i] > max) {
            max = T.buffer[i]; // Update juaranya
        }
    }
    
    // 4. Setelah selesai keliling, max pasti berisi yang paling besar
    return max;
}
/* Prekondisi : list T tidak kosong */
/* Mengirimkan nilai anomali tertinggi di list */

ElType lowestAnomaly(ListAnomali T){
    ElType temp = T.buffer[0]; // Pakai ElType
    for (int i = 1; i < T.nEff; i++) { // Mulai dari 1 saja
        if (T.buffer[i] < temp) { // TANDA DIUBAH JADI <
            temp = T.buffer[i];
        }
    }
    return temp;
}
/* Prekondisi : list T tidak kosong */
/* Mengirimkan nilai anomali terendah di list */

void shiftRightByK(ListAnomali *T, int K) {
    if (isEmpty(*T) || K <= 0) return;

    // 1. Geser elemen dari belakang ke depan agar tidak tertimpa
    for (int i = T->nEff - 1; i >= 0; i--) {
        if (i + K < MAX_CAPACITY) {
            T->buffer[i + K] = T->buffer[i];
        }
    }

    // 2. Isi bagian depan yang kosong dengan ELEM_UNDEF
    for (int i = 0; i < K && i < MAX_CAPACITY; i++) {
        T->buffer[i] = ELEM_UNDEF;
    }

    // 3. Update nEff: Sekarang nEff adalah nEff lama + K, 
    // tapi tidak boleh lebih dari MAX_CAPACITY
    T->nEff = (T->nEff + K > MAX_CAPACITY) ? MAX_CAPACITY : T->nEff + K;
}
/* Prekondisi : list T tidak kosong dan (last_idx + K) < max_anomaly_count */
/* Menggeser seluruh elemen ke kanan sebanyak K kali */
/* Gunakan ELEM_UNDEF sebagai elemen baru di kiri */
/* Contoh, untuk K = 2, maka [1,2,3] menjadi [ELEM_UNDEF,ELEM_UNDEF,1,2,3]*/

void reverseList(ListAnomali *T){
    if (isEmpty(*T))
    {
        return;
    }
    for (int i = 0; i < T->nEff /2 ; i++)
    {
        int temp = T->buffer[i];
        T->buffer[i] = T->buffer[T->nEff -1-i];
        T->buffer[T->nEff - 1 - i] = temp;
    }
    
    
    
}
/* Prekondisi : list T tidak kosong */
/* Membalikkan list T */
/* Contoh, untuk untuk list [1,2,3], maka menjadi [3,2,1] */

void extractExtremeAnomalies(ListAnomali *T_src, ListAnomali *T_dst) {
    // 1. Cek dulu apakah ada elemen ekstrem di T_src
    boolean hasExtreme = false;
    for (int i = 0; i < countAnomaly(*T_src); i++) {
        if (T_src->buffer[i] <= -100 || T_src->buffer[i] >= 100) {
            hasExtreme = true;
            break; // Cukup ketemu satu saja
        }
    }

    // Jika tidak ada, jangan ubah T_dst sama sekali
    if (!hasExtreme) return;

    // 2. Kosongkan T_dst (Overwrite)
    CreateListAnomali(T_dst);

    // 3. Pindahkan elemen
    int i = 0;
    while (i < countAnomaly(*T_src)) {
        if (T_src->buffer[i] <= -100 || T_src->buffer[i] >= 100) {
            // Masukkan ke posisi paling belakang T_dst
            insertAt(T_dst, T_src->buffer[i], countAnomaly(*T_dst));
            
            // Hapus dari T_src
            ElType buang;
            deleteAt(T_src, i, &buang);
            
            // CATATAN PENTING:
            // Di sini kita TIDAK melakukan i++, karena setelah di-delete, 
            // elemen kanan akan geser ke kiri (masuk ke indeks i saat ini).
        } else {
            // Kalau bukan ekstrem, baru lanjut ke indeks berikutnya
            i++;
        }
    }
}/* Prekondisi : list T_src dan T_dst sembarang (bisa kosong atau bisa terisi) */
/* MEMINDAHKAN elemen anomali ekstrim dari T_src ke T_dst secara urut dari kiri ke kanan */
/* Anomali ekstrem didefinisikan sebagai anomali dengan nilai <= -100 dan >= 100*/
/* Contoh: */
/* untuk untuk list T_src [0, 100, -200], maka h:*/
/*     T_src akan berisi [0]  */
/*     T_dst akan berisi [100, -200]  */
/* Jika T_dst tidak kosong dan ada elemen yang bisa diekstrak : semua nilai T_dst dihilangkan (List di overwrite) */
/* Jika T_dst tidak kosong dan tidak ada elemen yang bisa diekstrak : jangan ubah T_dst */

