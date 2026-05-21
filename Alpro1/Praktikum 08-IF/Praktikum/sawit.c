#include<stdio.h>
#include<stdlib.h>

#define ROW_CAP 100
#define COL_CAP 100
typedef int IdxType; 
typedef int ElType;
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

typedef struct
{
    ElType mem[ROW_CAP][COL_CAP];
    int rowEff; 
    int colEff; 
} Matrix;

void createMatrix(int nRows, int nCols, Matrix *m){
     ROW_EFF(*m) = nRows;
     COL_EFF(*m) = nCols;
}

int main (){
     Matrix petak;
     scanf("%d",&ROW_EFF(petak));
     scanf("%d",&COL_EFF(petak));

     for (int i = 0; i < ROW_EFF(petak); i++)
     {
          for (int j = 0; j < COL_EFF(petak); j++)
          {
                scanf("%d", &ELMT(petak,i,j));
          }
     }


int max = 0;
int totalSquares = 0;

for (int size = 1; size <= ROW_EFF(petak) && size <= COL_EFF(petak); size++) {
    int count = 0;
    for (int i = 0; i <= ROW_EFF(petak) - size; i++) {
        for (int j = 0; j <= COL_EFF(petak) - size; j++) {
            int isSquare = 1;
            for (int di = 0; di < size && isSquare; di++) {
                for (int dj = 0; dj < size && isSquare; dj++) {
                    if (ELMT(petak, i + di, j + dj) != 1) {
                        isSquare = 0;
                    }
                }
            }
            if (isSquare) {
                count++;
                max = size;
            }
        }
    }
    totalSquares += count;
}

printf("MAX %d\n", max * max);
printf("TOTAL %d\n", totalSquares);

return 0;

}
