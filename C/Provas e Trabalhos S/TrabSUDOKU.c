#include <stdio.h>
#include <stdlib.h>
#define n 9

int **criaMatriz();
void escreveMatriz(int **m);
void leMatriz(int **m, FILE *arq);
int verificarRepet(int **m, int LinI, int LinF, int ColI, int ColF);
int repetLinhas(int **m);

void main(){
    int **mat;
    int a, b, c, d, e, f, g, h, i, j;  //essas variáveis são para facilitar a análise do que retornou da função e manipular esses dados

    mat = criaMatriz();

    FILE * arq;
    arq = fopen("MallocSudoku.txt", "r");
    leMatriz(mat, arq);
    fclose(arq);

    printf("\nMATRIZ: \n");
    escreveMatriz(mat);

    printf("\nTESTE CONTADORES: ");

    a = verificarRepet(mat, 0, 2, 0, 2); //estou trabalhando com 9 matrizes 3x3, ao inves de 1 matriz 9x9
    b = verificarRepet(mat, 3, 5, 0, 2); //e passo as coordenadas de inicio e fim de cada linha e coluna
    c = verificarRepet(mat, 6, 8, 0, 2); 
    d = verificarRepet(mat, 0, 2, 3, 5);
    e = verificarRepet(mat, 0, 2, 6, 8);
    f = verificarRepet(mat, 3, 5, 3, 5);
    g = verificarRepet(mat, 3, 5, 6, 8);
    h = verificarRepet(mat, 6, 8, 3, 5);
    i = verificarRepet(mat, 6, 8, 6, 8);
    j = repetLinhas(mat);

    printf("\n");

    if(a==1 && b==1 && c==1 && d==1 && e==1 && f==1 && g==1 && h==1 && i==1 && j==1){ 
        printf("\nSOLUCAO VALIDA!!!");           //se todos forem igual 1, não houve repetição
    }else
        printf("\nSOLUCAO INVALIDA!!!");    //se qualquer um for diferente, então houve repetição
}

int **criaMatriz(){
    int i;
    int **m;
    m = malloc(n * sizeof(int));
    for(i=0; i<n; i++){
        m[i] = malloc(n * sizeof(int));
    }
    return(m);
}

void leMatriz(int **m, FILE *arq){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            fscanf(arq, "%d", (m[i]+j));
        }
    }
}

void escreveMatriz(int **m){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", *(m[i]+j));
        }
        printf("\n");
    }
}

int verificarRepet(int **m, int LinI, int LinF, int ColI, int ColF){
    int i, j, k, l, cont;
    cont = 0;

    for(l=LinI; l<=LinF; l++){    //travo algum elemento e comparo ele com todos os outros
        for(k=ColI; k<=ColF; k++){  //repito isso até que todos os elementos da submatriz sejam comparados
            for(i=LinI; i<=LinF; i++){
                for(j=ColI; j<=ColF; j++){
                    if(*(m[l]+k) == *(m[i]+j)){
                        cont++;
                    }
                    if(*(m[l]+k) > 9 || *(m[l]+k) < 1){   //caso algum elemento seja menor/igual a zero OU 
                        cont++;                           //seja maior que 9, não dá pra ser sudoku assim
                    }                                     //então eu ja coloco meu cont de um modo que ele 
                }                                         //retorna 0 no final da função
            }
        }
    }
    printf("%d ", cont);
    if(cont == 9){   //eu marco um elemento e comparo ele com todos os 9 elementos, como a matriz 
        return (1);  //tem 9 elementos eu faço esse processo 9 vezes. Porém para cada elemento a única
    }else            //repetição é ele mesmo, ou seja, se cont=9 quer dizer que não houve nenhuma repetição
        return (0);
}

int repetLinhas(int **m){
    int i, j, aux;
    int cont;

    for(i=0; i<9; i++){     //percorro todas as linhas da matriz
        for(aux=1; aux<10; aux++){    //como as únicas soluções válidas são de 1 a 9, vou comparar só de 1 a 9
            cont = 0;    //sempre que aux mudar, reseto cont para 0 pois ele é que verifica repetição por número
            for(j=0; j<9; j++){    //percorrendo todas as colunas da matriz
                if(aux == *(m[i]+j)){    //se aux for igual a algum elemento, cont++
                    cont++;   //em sudoku válido aux deve ser sempre 1, pois aux só 
                }             //vai ser igual a ele mesmo e logo não há nenhuma repetição
                if(cont > 1){    //se cont foi maior que 1 para qualquer elemento de aux, então
                    return (0);    //houve alguma repetição em alguma coluna e imediatamente retorno 0 
                }
            }
        }
    }

    return (1);
}