#include <stdio.h>

int main (){
    int D, M, fd, fm, ld, lm;
    //Kenapa harus 1? bebas aja yang penting biar whilenya jalan dulu, nnti juga di timpuk value baru
    int Dhasil = 1, Mhasil = 1;

    if (scanf("%d %d", &D, &M) != 2) return 0;

    while (Dhasil > 0 && Mhasil > 0)
    {
        // 1. Cari digit dari nilai D dan M SAAT INI
        ld = D % 10;
        lm = M % 10;

        fd = D;
        while (fd >= 10) { fd /= 10; }
        
        fm = M;
        while (fm >= 10) { fm /= 10; }

        // 2. Hitung hasil pengurangan ronde ini
        Dhasil = D - (fm + lm); 
        Mhasil = M - (fd + ld); 

        // 3. PENTING: Update nilai D dan M untuk dipakai ronde berikutnya
        D = Dhasil;
        M = Mhasil;
    }
    
    // 4. Cek hasil akhir setelah loop berhenti
    if (Dhasil == Mhasil || (Dhasil < 0 && Mhasil < 0))
    {
        printf("Wattles\n");
    }
    else if (Dhasil < 0)
    {
        printf("Mebel\n");
    }
    else if (Mhasil < 0)
    {
        printf("Deeper\n");
    }

    return 0;
}