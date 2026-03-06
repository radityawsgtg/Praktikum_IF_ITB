#include <stdio.h>
/*Pada intinya pelajari dulu gimana cara buat segitiga pake loop
coba ubah beberapa batasan pada loop dan liat apa yang terjadi */
int main (){
    int n;
    do
    {
        scanf("%d",&n);
    } while (n < 3);

    
    for (int x = 1; x < (n); x++)
    {
        for (int i = x; i < (n+1); i++)
    {
        for (int j = 0; j < (n-i); j++)
        {
            printf(" "); /*Biar gampang visualiasinya coba kalian ubah " " jadi "_"*/
        }
        for (int k = 0; k < (2*i - 1); k++)
        {
            printf("*");
        }
        printf("\n");
    }
    }
    for (int g = 0; g < n; g++)
    {
        for (int p = 0; p < (n-2); p++)
        {
            printf(" ");
        }
        
        printf("***");
        printf("\n");
    }
    
    
    


}