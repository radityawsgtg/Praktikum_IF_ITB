#include <stdio.h>

#define ROW_CAP 100
#define COL_CAP 100

typedef struct {
    int konten[ROW_CAP][COL_CAP];
    int rowEff;
    int colEff;
} Matrix;

int main(){
    Matrix M1;
    int row,col;
    scanf("%d",&row);
    scanf("%d",&col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d",&M1.konten[i][j]);
        }
        
    }
    for (int k = 0; k < col; k++)
    {
        for (int l = row-1; l >= 0; l--)
        {
            printf("%d",M1.konten[l][k]);
            if (l>0)
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
    
    

    return 0;

}