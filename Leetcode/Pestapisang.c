#include <stdio.h>
int hitungtotalpisang(int a, int b, int c, int d,int e){
    int total;
    total = a + b +c + d + e ;
    return total;
}

float rata(float masukan){
    float hasil;
    hasil = masukan / 5.0 ;
    return hasil;
}

void Pestaberhasil(int g, float f){
    printf("%f",f);
    if (g >= 10)
    {
        printf (" Pesta minion sukses ");
    }
    else
    printf("Pesta minion gagal");

}

int main (){
    int a,b,c,d,e,total;
    float rata2;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    total = hitungtotalpisang(a,b,c,d,e);
    rata2 = rata(hitungtotalpisang(a,b,c,d,e));
    Pestaberhasil(total,rata2);
}