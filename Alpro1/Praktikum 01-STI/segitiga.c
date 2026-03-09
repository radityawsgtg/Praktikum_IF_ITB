#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main (){
    double a,b,c;
    //Membaca input
    if (scanf (" %lf %lf %lf", &a,&b,&c) != 3 ) return 0;
    
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Tidak valid\n");
        return 0;
    }

    bool ab = fabs(a - b) < 0.001;
    bool bc = fabs(b - c) < 0.001;
    bool ac = fabs(a - c) < 0.001;
    
    bool siku = (fabs(a*a + b*b - c*c) < 0.001) || (fabs(a*a + c*c - b*b) < 0.001) || (fabs(b*b + c*c - a*a) < 0.001);
    if (ab && bc) {
        printf("Segitiga Sama Sisi\n");
    } 
    else if (siku) {
        if (ab || bc || ac) {
            printf("Segitiga Siku-Siku Sama Kaki\n");
        } else {
            printf("Segitiga Siku-Siku\n");
        }
    } 
    else if (ab || bc || ac) {
        printf("Segitiga Sama Kaki\n");
    } 
    else {
        printf("Segitiga Sembarang\n");
    }

    return 0;
}