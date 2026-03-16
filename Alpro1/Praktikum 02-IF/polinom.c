#include<stdio.h>

int f(int x){
    int hasil;
    hasil = (x*x) + (5*x) + 7;
    return hasil;
}
int g(int x){
    int hasil;
    hasil = (x*x*x*x) + (2*x) + 1;
    return hasil;
}

int main (){
    int masukan,keluaran_1,keluaran_2;
    scanf("%d", &masukan);
    keluaran_1 = g(masukan);
    keluaran_2 = f(keluaran_1);
    printf("%d\n",keluaran_2);
    return 0;
}