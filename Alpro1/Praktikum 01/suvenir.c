#include <stdio.h>
int main (){
    int n;
    do
    {
    scanf ("%d", &n);
    } while (n < 0);
    
    
    int count = 0;
    int ndumy = n ;
    
    for (int i = 0; i < n; i++)
    {
            int pengurang = (ndumy-1);
            for (int j = 0; j < (n-pengurang); j++)
            {
                count = count + 1;
                printf("%d",count);
            }
            printf("\n");
            ndumy = (ndumy -1);
    
        

    }
    

}