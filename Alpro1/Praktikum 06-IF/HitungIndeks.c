#include<stdio.h>
#include"HitungIndeks.h"

/*#define MAX_NUM_MATKUL 100
#define MAX_NAME_LEN 50

typedef struct {
    char NamaMatkul[MAX_NUM_MATKUL][MAX_NAME_LEN];
    float Nilai[MAX_NUM_MATKUL];
    int SKS[MAX_NUM_MATKUL];
    int Kehadiran[MAX_NUM_MATKUL];
    char Indeks[MAX_NUM_MATKUL];
    int NEff;
} Transkrip;

*/
void BuatTranskrip (Transkrip *T){
    T->NEff = 0;
}

int AmbilJumlahMatkul (Transkrip T){
    return T.NEff;
}
/* Mengembalikan banyaknya mata kuliah pada transkrip */

void AmbilMatkul (Transkrip *T, char *nama, float nilai, int sks, int kehadiran){
    if (AmbilJumlahMatkul(*T)!=MAX_NUM_MATKUL)
    {
        if (nilai >=0 && nilai <= 100 && sks>= 1 && sks <= 4 && nama != NULL && nama[0] != '\0')
        {
            strcpy(T->NamaMatkul[T->NEff],nama); /*cuma butuh alamat doang*/
            T->Nilai[T->NEff] = nilai;
            T->SKS[T->NEff] = sks;
            T->Kehadiran[T->NEff]= kehadiran;
            T->NEff++;
        }
    }
    

}
/* Menambahkan matkul pada transkrip jika masih ada kapasitas mata kuliah pada transkrip dan data mata kuliah valid.
   Nilai dan kehadiran berada pada range 0-100, sks berada pada range 1-4, dan nama tidak boleh kosong. */

float HitungNilai (Transkrip T, int i){
    float nigab;
    if (i < T.NEff && i >= 0)
    {
        nigab = (0.95 * T.Nilai[i] + (0.05 * T.Kehadiran[i]));
        return nigab;
    }
    return -1;
    
}
/* Mengembalikan nilai mata kuliah pada indeks ke-i yang sudah memperhitungkan nilai mentah sebesar 95% dan nilai kehadiran sebesar 5%.
 Jika mata kuliah tidak ditemukan pada transkrip, kembalikan -1 */

char HitungIndeks (Transkrip T, int i){
    if (T.Nilai[i] == -1) {
        return '-';
    }

    // Penentuan Indeks (sesuai spesifikasi di .h)
    if (T.Nilai[i] >= 80.0) {
        return 'A';
    } else if (T.Nilai[i] >= 70.0) {
        return 'B';
    } else if (T.Nilai[i] >= 60.0) {
        return 'C';
    } else if (T.Nilai[i] >= 50.0) {
        return 'D';
    } else {
        return 'E';
    }

}
/* Mengembalikan nilai mata kuliah pada indeks ke-i yang sudah diterjemahkan ke dalam indeks
    Dengan ketentuan indeks sebagai berikut:
    A: 100.0 >= nilai >= 80.0
    B: nilai >= 70.0
    C: nilai >= 60.0
    D: nilai >= 50.0
    E: 0 =< nilai < 50.0
Jika mata kuliah tidak ditemukan pada transkrip atau nilainya tidak valid, kembalikan '-' */

void SimpanIndeks (Transkrip *T){
    for (int i = 0; i < T->NEff; i++)
    {
    T->Indeks[i] = HitungIndeks(*T, i);    }
    
}
/* Memasukkan data indeks tiap matkul pada transkrip */

char HitungIndeksTotal (Transkrip T){
    SimpanIndeks(&T);
    int totalSKS=0;
    float totalpoint= 0.0;

    for (int i = 0; i < T.NEff; i++)
    {
        float pointMatkul = 0.0;
        switch (T.Indeks[i])
        {
        case 'A':
            pointMatkul = 4.0;
            break;
        case 'B':
            pointMatkul = 3.0;
            break;
        case 'C':
            pointMatkul = 2.0;
            break;
        case 'D':
            pointMatkul = 1.0;
            break;
        case 'E':
            pointMatkul = 0.0;
            break;
        default:
            pointMatkul = 0.0;
            break;
        }
        totalpoint = totalpoint + (T.SKS[i] * pointMatkul);
        totalSKS = totalSKS + T.SKS[i];
    }
    if (totalSKS == 0) return '-';
    float IP = totalpoint / totalSKS;
    if (IP >= 3.5) return 'A';
    else if (IP >= 2.5) return 'B';
    else if  (IP >= 1.5) return 'C';
    else if  (IP >= 1.5) return 'D';
    else return 'E';
    
}
/* Mengembalikan indeks keseluruhan mata kuliah berdasarkan transkrip.
   Fungsi ini akan memanggil SimpanIndeks secara internal sebelum menghitung.
    1. Konversi indeks tiap matkul ke poin, jika ada indeks yang tidak valid, maka poinnya dianggap 0.0
        A = 4.0, B = 3.0, C = 2.0, D = 1.0, E = 0.0
    2. Hitung rata-rata:
        (Total (SKS * poin)) / Total SKS
    3. Tentukan indeks total berdasarkan range IP berikut:
        A: 3.5 <= IP <= 4.0
        B: 2.5 <= IP < 3.5
        C: 1.5 <= IP < 2.5
        D: 0.5 <= IP < 1.5
        E: 0.0 <= IP < 0.5
Jika tidak ada mata kuliah pada transkrip atau hasil tidak valid, kembalikan '-' */

bool CekKelulusan (Transkrip T) {
    char indeksTotal = HitungIndeksTotal(T);
    
    if (indeksTotal == 'A' || indeksTotal == 'B' || indeksTotal == 'C') {
        return true;
    }
    
    return false; // Jangan lupa return false untuk D, E, atau '-'
}
/* Mengembalikan nilai true jika pemilik transkrip ini lulus (indeks total >= C) */

void CetakTranskrip (Transkrip T) {
    // 1. Cek apakah transkrip kosong
    if (T.NEff == 0) {
        printf("Transkrip masih kosong\n");
    } else {
        // 2. Traversal/Looping untuk mencetak setiap mata kuliah
        for (int i = 0; i < T.NEff; i++) {
            printf("Mata Kuliah: %s\n", T.NamaMatkul[i]);
            
            // Gunakan HitungNilai untuk mendapatkan nilai 95% + 5%
            printf("Nilai: %.2f\n", HitungNilai(T, i));
            
            // Gunakan HitungIndeks untuk mendapatkan huruf A-E
            printf("Indeks: %c\n", HitungIndeks(T, i));
            
            // Print newline antar mata kuliah agar rapi
            printf("\n");
        }

        // 3. Bagian Summary (Indeks Akhir & Kelulusan)
        char indeksAkhir = HitungIndeksTotal(T);
        printf("Indeks Akhir: %c\n", indeksAkhir);

        // Gunakan CekKelulusan untuk menentukan status
        if (CekKelulusan(T)) {
            printf("Status Kelulusan: LULUS\n");
        } else {
            printf("Status Kelulusan: TIDAK LULUS\n");
        }
    }
}
/* Mencetak data transkrip dengan format (akhiri dengan newline):
    Mata Kuliah: <Nama Mata Kuliah ke-1>
    Nilai: <Nilai Mata Kuliah ke-1>
    Indeks: <Indeks Mata Kuliah ke-1>

    Mata Kuliah: <Nama Mata Kuliah ke-2>
    Nilai: <Nilai Mata Kuliah ke-2>
    Indeks: <Indeks Mata Kuliah ke-2>

    ...

    Mata Kuliah: <Nama Mata Kuliah ke-N>
    Nilai: <Nilai Mata Kuliah ke-N>
    Indeks: <Indeks Mata Kuliah ke-N>

    Indeks Akhir: <Indeks Akhir pada Transkrip>
    Status Kelulusan: <"LULUS" / "TIDAK LULUS">
Perhatikan bahwa nilai disini adalah nilai yang MEMPERHITUNGKAN KEHADIRAN dan ambil dua angka dibelakang koma.
Jika transkrip tidak memiliki mata kuliah, cetak "Transkrip masih kosong" */