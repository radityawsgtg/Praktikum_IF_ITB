#include <stdio.h>
int main (){
    int y;
    do
    {
        scanf("%d", &y);
        if (y <= 0)
        {
            printf("Masukan tidak Valid.");
        }
        
    } while (y <= 0);

    if (y % 400 != 0 && y % 100 != 0 && y % 4 == 0)
    {
        printf("Tahun kabisat\n");
    }
    else if (y % 4 != 0)
    {
        printf("Bukan tahun kabisat\n");
    }
    else if (y % 400 == 0)
    {
        printf("Tahun kabisat\n");
    }
    else if (y % 400 != 0 && y % 100 == 0)
    { 
        printf("Bukan tahun kabisat\n");
    }
    
    

    
    
    
}