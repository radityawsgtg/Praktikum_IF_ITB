#include <stdio.h>

int main (){
    int input;
    scanf ("%d", &input);
    int count = 0, max_value = 1;
    while (input != 1)
    {
        printf("%d \n", input);
        if (input > max_value)
        {
            max_value = input;
        }
        
        if (input % 2 == 0 )
        {
            input /= 2 ;
            count++ ;
        }
        else
        {
            input =( input *3 ) + 1 ;
            count++ ;
        }
        
        
    }
    printf("1\n");
    printf("Langkah : %d \n",count);
    printf ("Nilai Maskimum: %d", max_value);
    
    return 0;
}