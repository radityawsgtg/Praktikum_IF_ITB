#include <stdio.h>

int main (){
    int bilangan,count = 0;
    
    do
    {
        scanf("%d",&bilangan);
    } while (bilangan < 1);
    

    while (bilangan > 1)
    {
        if (bilangan % 2 == 0)
        {
            bilangan = bilangan / 2;
            count++;
        }
        else
        {
            bilangan = (bilangan * 3) + 1;
            count++;
        }
        
    }
    
    printf("%d \n", count);
    return 0;
}