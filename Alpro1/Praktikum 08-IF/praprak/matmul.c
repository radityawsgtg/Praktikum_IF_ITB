#include <stdio.h>

#define ROW_CAP 100
#define COL_CAP 100

typedef struct {
    int konten[ROW_CAP][COL_CAP];
    int rowEff;
    int colEff;
} Matrix;

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    Matrix mout;
    mout.rowEff = m1.rowEff;
    mout.colEff = m2.colEff;

    for (int i = 0; i < m1.rowEff; i++) {
        for (int j = 0; j < m2.colEff; j++) {
            mout.konten[i][j] = 0; 
            for (int k = 0; k < m1.colEff; k++) { 
                mout.konten[i][j] += m1.konten[i][k] * m2.konten[k][j];
            }
        }
    }
    return mout;
}

int main() {
    Matrix m1, m2;
    int n, k, p;

    if (scanf("%d %d %d", &n, &k, &p) != 3) return 0;

    m1.rowEff = n;
    m1.colEff = k;
    m2.rowEff = k;
    m2.colEff = p;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &m1.konten[i][j]);
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &m2.konten[i][j]);
        }
    }

    Matrix out = multiplyMatrix(m1, m2);

    for (int i = 0; i < out.rowEff; i++) {
        for (int j = 0; j < out.colEff; j++) {
            printf("%d", out.konten[i][j]);
            if (j < out.colEff - 1) {
                printf(" "); 
            }
        }
        printf("\n");
    }

    return 0;
}