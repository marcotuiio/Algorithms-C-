#include <stdio.h>
#include <stdlib.h>

int **criaMatriz();
void escreveMatriz(int **m);
void leMatriz(int **m, FILE *matriz);
int verifSubMatriz(int **m, int LinIni, int LinFin, int ColIni, int ColFin);
int verifLinhas(int **m);
int verifDiagonalPrincipal(int **m);
int verifDiagonalSecundaria(int **m);

void main(){
    int **sudoku;
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;

    sudoku = criaMatriz();

    FILE *matriz;
    matriz = fopen("sudokuPROVA.txt", "r");
    leMatriz(sudoku, matriz);
    fclose(matriz);

    printf("\nMATRIZ DO SUDOKU:\n");
    escreveMatriz(sudoku);

    printf("\nContadores Sub Matrizes: ");

    a = verifSubMatriz(sudoku, 0, 2, 0, 3); //estou trabalhando com 12 sub matrizes 3x4, e passo
    b = verifSubMatriz(sudoku, 0, 2, 4, 7); //as coordenadas de inicio e fim de cada linha e coluna
    c = verifSubMatriz(sudoku, 0, 2, 8, 11);
    d = verifSubMatriz(sudoku, 3, 5, 0, 3);
    e = verifSubMatriz(sudoku, 3, 5, 4, 7); 
    f = verifSubMatriz(sudoku, 3, 5, 8, 11);
    g = verifSubMatriz(sudoku, 6, 8, 0, 3);
    h = verifSubMatriz(sudoku, 6, 8, 4, 7);
    i = verifSubMatriz(sudoku, 6, 8, 8, 11);
    j = verifSubMatriz(sudoku, 9, 11, 0, 3);
    k = verifSubMatriz(sudoku, 9, 11, 4, 7);
    l = verifSubMatriz(sudoku, 9, 11, 8, 11);
    m = verifLinhas(sudoku);
    n = verifDiagonalPrincipal(sudoku);
    o = verifDiagonalSecundaria(sudoku);

    //if(a==1 && b==1 && c==1 && d==1 && e==1 && f==1 && g==1 && h==1 && i==1 && j==1 && k==1 && l==1 && m==1 && n==1 && o==1){
    if(a==1 && b==1 && c==1 && d==1 && e==1 && f==1 && g==1 && h==1 && i==1 && j==1 && k==1 && l==1){
        printf("\nSOLUCAO VALIDA!!!\n");
    }else
        printf("\nSOLUCAO INVALIDA!!!\n");
    
}

int **criaMatriz(){
    int i;
    int **m;
    m = malloc(12 * sizeof(int));
    for(i=0; i<12; i++){
        m[i] = malloc(12 * sizeof(int));
    }
    return(m);
}

void leMatriz(int **m, FILE *matriz){
    int i, j;
    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
            fscanf(matriz, "%d", (m[i]+j));
        }
    }
}

void escreveMatriz(int **m){
    int i, j;
    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
            printf("%d ", *(m[i]+j));
        }
        printf("\n");
    }
}

int verifSubMatriz(int **m, int LinIni, int LinFin, int ColIni, int ColFin){
    int i, j, cont;
    int k, l;
    cont = 0;

    for(k=LinIni; k<=LinFin; k++){             
        for(l=ColIni; l<=ColFin; l++){
            for(i=LinIni; i<=LinFin; i++){      //vou percorrer as sub matriz comparando os seus elementos com esses valores
                for(j=ColIni; j<=ColFin; j++){  //e desse modo, devo obter cont=12 pois cada elemento só aparece uma vez
                    if(*(m[k]+l) == *(m[i]+j)){
                        cont++;
                    }
                    if(*(m[i]+j) > 12 || *(m[i]+j) < 1){   //caso algum elemento seja menor/igual a zero OU 
                        cont++;                           //seja maior que 12, não dá pra ser sudokuX assim.
                    }                                     //então eu ja coloco meu cont de um modo que ele 
                }                                         //retorna 0 no final da função
            }
        }
    }

    printf("%d ", cont);
    if(cont == 12){   //eu marco um elemento e comparo ele com todos os 12 elementos, como a matriz 
        return (1);   //tem 12 elementos eu faço esse processo 12 vezes. Porém para cada elemento a única
    }else             //repetição é ele mesmo, ou seja, se cont=12 quer dizer que não houve nenhuma repetição,
        return (0);   //não houve números menores que 1 e nem números maiores que 12
}

int verifLinhas(int **m){
    int i, j, aux;
    int cont;

    for(i=0; i<12; i++){              //percorro todas as linhas da matriz.
        for(aux=1; aux<=12; aux++){         //como as únicas soluções válidas são de 1 a 9, vou comparar só de 1 a 9 e
            cont = 0;                       //sempre que aux mudar, reseto cont para 0 pois ele é que verifica repetição por número.
            for(j=0; j<12; j++){      //percorrendo todas as colunas da matriz.
                if(aux == *(m[i]+j)){       //se aux for igual a algum elemento, cont++
                    cont++;                 //em sudoku válido cont deve ser sempre 1, pois aux só vai ativar cont++ 
                }                           //quando for igual a ele mesmo e logo não há nenhuma repetição
                if(cont > 1){               //se cont foi maior que 1 para qualquer elemento de aux, então
                    printf("\nContador Matriz Inteira: %d", cont); //houve alguma repetição em alguma coluna e imediatamente retorno 0 
                    return (0);             
                }
            }
        }
    }
    printf("\nContador Matriz Inteira: %d", cont);
    return (1);
}

int verifDiagonalPrincipal(int **m){
    int i, aux, cont = 0;

    for(aux=1; aux<=12; aux++){
        for(i=0; i<12; i++){
            if(aux == *(m[i]+i)){
                cont++;
            }
        }
    }
    printf("\nContador Diagonal Principal: %d\n", cont);
    if(cont == 12){
        return(1);
    }else
        return(0);
}

int verifDiagonalSecundaria(int **m){ //0 11, 1 10, 2 9, 3 8, 4 7, 5 6, 6 5, 7 4, 8 3, 9 2, 10 1, 11 0
    int i, j, aux, cont = 0;

    for(aux=1; aux<=12; aux++){
        i = 0;
        for(j=11; j>=0; j--){
            if(aux == *(m[i]+j)){
                cont++;
            }
            i++;
        }
    }
    printf("Contador Diagonal Secundaria: %d\n", cont);
    if(cont == 12){
        return (1);
    }else
        return (0);

}
