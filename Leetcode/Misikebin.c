#include <stdio.h>
#include <stdbool.h>

bool isprime (int bil){

    if (bil <= 1)
    {
        return false;
    }

    for (int i = 2; i < bil; i++)
    {
        if (bil % i == 0)
        {
            return false;
        }
        
    }

    return true;
}

int main (){
    int masukan1,masukan2;
    scanf("%d %d",&masukan1,&masukan2);
    int nilai;
    int count = 0;
    for (int z = masukan1; z < masukan2; z++)
    {
        if (isprime(z) == true)
        {
            printf("%d", z);
            printf("\n");
            count++;
        }
        
    }
    printf("Banyaknya bil prima : %d",count);

    return 0;

}