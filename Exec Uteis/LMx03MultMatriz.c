#include <stdio.h>
#include <stdlib.h>
#define LINHA 3   // definindo linhas da matriz PRODUTO
#define COLUNA 5  // definindo colunas da matriz PRODUTO
#define REGRA 4
// Para mult. matrizes a qntd de colunas de A deve ser igual a qntd de linhas de B
// Um matriz C=A*B terá a qntd de linhas de A e a qntd de colunas de B

void mult(int a[LINHA][REGRA], int b[REGRA][COLUNA]);
void escreveMatriz(int lin, int col, int matriz[lin][col]);

void main() {
    int i, j;
    int A[LINHA][REGRA], B[REGRA][COLUNA];

    FILE* fp;
    fp = fopen("LMx03mz.txt", "r");

    for (i = 0; i < LINHA; i++) {
        for (j = 0; j < REGRA; j++) {
            fscanf(fp, "%d", &A[i][j]);
        }
    }
    for (i = 0; i < REGRA; i++) {
        for (j = 0; j < COLUNA; j++) {
            fscanf(fp, "%d", &B[i][j]);
        }
    }
    fclose(fp);

    printf("Matriz A: \n");
    escreveMatriz(LINHA, REGRA, A);
    printf("\n");
    printf("Matriz B: \n");
    escreveMatriz(REGRA, COLUNA, B);
    printf("\n");
    printf("C = A x B: \n");
    mult(A, B);
}

void escreveMatriz(int lin, int col, int matriz[lin][col]) {
    int m, n;
    for (m = 0; m < lin; m++) {
        for (n = 0; n < col; n++) {
            printf("%d ", matriz[m][n]);
        }
        printf("\n");
    }
}

void mult(int a[LINHA][REGRA], int b[REGRA][COLUNA]) {
    int i, j, soma, n;
    int C[LINHA][COLUNA];
    soma = 0;

    for (j = 0; j < LINHA; j++) {          // j controla linha da matriz produto C e linha de A
        for (n = 0; n < COLUNA; n++) {     // n controla coluna da matriz produto C e coluna de B
            for (i = 0; i < REGRA; i++) {  // i controla colunas da matriz A e linhas da matriz B
                soma = soma + a[j][i] * b[i][n];
            }
            C[j][n] = soma;
            soma = 0;
        }
    }

    escreveMatriz(LINHA, COLUNA, C);
}