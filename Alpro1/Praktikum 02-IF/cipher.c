#include <stdio.h>

int isprime (int bil){

    if (bil <= 1)
    {
        return 0;
    }

    for (int i = 2; i < bil; i++)
    {
        if (bil % i == 0)
        {
            return 0;
        }
        
    }

    return 1;
}

int Sum(int x){
    int total = 0;
    int digit;
    while (x != 0)
    {
        digit = x % 10;
        total = total + digit;
        x = x /10;
    }
    return total;
}

int Cekdigit(int x){
    int digit;
        while (x != 0)
    {
        digit = x % 10;
        if (isprime(digit) == 0)
        {
            return 0;
        }
        
        x = x /10;

        return 1;
    }
}

int main(){
    int masukan,prima,sum;
    scanf("%d", &masukan);
    sum = Sum(masukan);
    if (isprime(masukan) == 1 && isprime(Sum(masukan))== 1 && Cekdigit(masukan)== 1)
    {
        printf("1\n");
    }
    else
    printf("0\n");
    
    
}
