#include <stdio.h>
#include <stdlib.h>

int main (){

    int N;
    scanf("%d",&N);
    int x[200];
    int y[200];        
    int jarak_maksimum;


    for (int i = 0; i < N; i++)
    {
        scanf(" %d %d", &x[i] , &y[i]);
    }

    for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                int jarak_temp = abs(x[i]-x[j]) + abs(y[i]-y[j]);
                if (jarak_temp > jarak_maksimum)
                {
                    jarak_maksimum = jarak_temp;
                }
                
            }
            
            
        }
    printf("%d\n",jarak_maksimum);
    
}