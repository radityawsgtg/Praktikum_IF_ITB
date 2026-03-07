#include <stdio.h>
#include <math.h>
int main (){
    int a,b,c;
    do
    {
        scanf ("%d %d %d", &a, &b, &c);
    } while (a<0 || b<0 || c < 0 || a + b > c || a + c > b || b + c > a);
    if (a == b && b == c)
    {
        printf("Segitiga sama sisi");
    }
    if (fabs(a^2 + b^2 - c^2))
    {
        /* code */
    }
    
    
    

    return 0;
}