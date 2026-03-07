#include <stdio.h>
int main (){
    int bilangan,jumlah = 0, hasil = 0;
    do
    {
        scanf("%d",&bilangan);
    } while (bilangan < 0);

    int ori = bilangan;

    while (bilangan > 0) //skema ambil bilangan kalau ga pake string gini, aga matematis dikit caranya
    {
        jumlah = bilangan % 10; // digit terakhir
        hasil = hasil + jumlah; // masukin digit terakhir ke variabel hasil
        bilangan = bilangan / 10; // biar lanjut ke digit selanjutnya
    }
    if (jumlah > 0 && jumlah % hasil == 0)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    
    
    
    
    return 0;
    

}