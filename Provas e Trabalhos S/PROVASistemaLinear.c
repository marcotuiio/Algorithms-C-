#include <stdio.h>
#include <stdlib.h>

float **criaMatriz(int n);
void leMatriz(float **mat, int n, FILE *arq);
void escreveMatriz(float **mat, int n);
void leTermosInd(float *B, FILE *arq, int n);
void calcularX(float **mat, float *B, int n);
void escreveX(float *result, int n);

void main(){
    int n;
    float **A;
    float *B;

    printf("Informe o numero de equacoes e incognitas do sistema: ");
    scanf("%d", &n);

    FILE *arq;
    arq = fopen("sistemaPROVA.txt", "r");

    A = criaMatriz(n);
    leMatriz(A, n, arq);
    printf("\nMatriz Triangular dos Coeficientes\n");
    escreveMatriz(A, n);
    printf("\n");

    B = malloc(n * sizeof(float));
    printf("Vetor dos Termos Independentes\n");
    leTermosInd(B, arq, n);

    fclose(arq);

    printf("\n\nValores para Xi: \n");
    calcularX(A, B, n);
    
    free(A);
    free(B);

}

float **criaMatriz(int n){
    int i;
    float **mat;
    mat = malloc(n * sizeof(float));
    for(i=0; i<n; i++){
        mat[i] = malloc((i+1) * sizeof(float));
    }
    return(mat);
}

void leMatriz(float **mat, int n, FILE *arq){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<=i; j++){
            fscanf(arq, "%f", (mat[i]+j));
        }
    }
}

void escreveMatriz(float **mat, int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<=i; j++){
            printf("%.1f ", *(mat[i]+j));
        }
        printf("\n");
    }
}

void leTermosInd(float *B, FILE *arq, int n){
    int i;
    for(i=0; i<n; i++){
        fscanf(arq, "%f ", B+i);
        printf("%.1f ", *(B+i));
    }
}

void calcularX(float **mat, float *B, int n){
    int i, j, aux;
    float *R; //vetor resultante com os valores de Xi
    R = malloc(n * sizeof(float));

    *(R+0) = *(B+0) / *(mat[0]+0);
    for(i=1; i<n; i++){
        aux = 0;
        for(j=0; j<i; j++){
            aux = aux + (*(mat[i]+j) * (*(R+j)));
        }
        *(R+i) = (*(B+i) - aux) / *(mat[i]+i);
    }
    escreveX(R, n);
}

void escreveX(float *result, int n){
    int i;
    for(i=0; i<n; i++){
        printf("X(%d) = %.1f\n", i+1, *(result+i));
    }
    free(result);
}
