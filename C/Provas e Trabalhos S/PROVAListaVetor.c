#include <stdio.h>
#include <stdlib.h>

struct cell {
    int vetor[3];
    struct cell *prox;
};
typedef struct cell celula;

int menu(void);
void inserirElemento(celula **ini, int valor1, int valor2, int valor3, int cont);
int removerElemento(celula **ini, int valor);
void compactarLista(celula **ini, int cont);
void escreverLista(celula *ini);
int removerCelula(celula **ini);

void main() {
    celula *inicio;
    inicio = NULL;
    int valor, valor2, valor3;
    int retorno;
    int op = 0;
    int contInsere = 0;
    int contCompacta = 0;

    while (op != 5) {
        op = menu();
        switch (op) {
            case 1:  // Inserir elemento
                contInsere++;
                if (contInsere == 3) {
                    contInsere = 0;
                }
                printf("\nInforme os TRES elementos que deseja inserir: ");
                scanf("%d %d %d", &valor, &valor2, &valor3);
                inserirElemento(&inicio, valor, valor2, valor3, contInsere);
                break;

            case 2:  // Remover elemento
                printf("\nInforme o elemento que deseja remover: ");
                scanf("%d", &valor);
                retorno = removerElemento(&inicio, valor);
                if (retorno == 1) {
                    printf("\nCONTEUDO REMOVIDO!!\n");
                } else if (retorno == 0) {
                    printf("\nCONTEUDO NAO ENCONTRADO!!\n");
                }
                break;

            case 3:  // Compactar
                contCompacta++;
                if (contCompacta == 3) {
                    contCompacta = 0;
                }
                printf("\nLista ANTES de Compactar:\n");
                escreverLista(inicio);

                compactarLista(&inicio, contCompacta);
                printf("\nLista DEPOIS de Compactar:\n");
                escreverLista(inicio);
                break;

            case 4:  // Listar
                printf("\n|****LISTA****|\n");
                escreverLista(inicio);
                break;

            case 5:  // Sair
                break;

            default:
                printf("\nOPCAO INCORRETA!!!");
                break;
        }
    }
}

int menu(void) {
    int op;
    printf("\n|1| - Inserir elemento\n");
    printf("|2| - Remover elemento\n");
    printf("|3| - Compactar lista\n");
    printf("|4| - Escrever lista\n");
    printf("|5| - Sair\n");
    printf(">> ");
    scanf("%d", &op);
    return (op);
}

void inserirElemento(celula **ini, int valor1, int valor2, int valor3, int cont) {
    int i = cont - 1, j;
    celula *aux;

    aux = (celula *)malloc(sizeof(celula));
    for (j = 0; j < 3; j++) {
        aux->vetor[j] = '\0';
    }

    if (aux->vetor[i] != '\0') {
        aux->vetor[0] = valor1;
        aux->vetor[1] = valor2;
        aux->vetor[2] = valor3;
    } else {
        aux = (celula *)malloc(sizeof(celula));
        for (j = 0; j < 3; j++) {
            aux->vetor[j] = '\0';
        }
        aux->vetor[0] = valor1;
        aux->vetor[1] = valor2;
        aux->vetor[2] = valor3;
    }
    aux->prox = NULL;

    if (*ini != NULL) {
        aux->prox = *ini;
    }
    *ini = aux;

    return;
}

int removerElemento(celula **ini, int valor) {
    int i = 0;
    if (*ini == NULL) {
        printf("\nA lista esta vazia.\n");
        return (-1);
    } else {
        celula *aux, *ant = NULL;
        aux = *ini;

        while ((aux->vetor[i] != valor)) {
            ant = aux;
            if (i < 3) {
                i++;
            } else if (i == 3) {
                i = 0;
                aux = aux->prox;
            }
        }

        if (aux->vetor[i] == valor) {
            aux->vetor[i] = '\0';

            if (aux->vetor[0] == '\0' && aux->vetor[1] == '\0' && aux->vetor[2] == '\0') {
                if (aux == *ini) {
                    *ini = (*ini)->prox;
                } else
                    ant->prox = aux->prox;

                free(aux);
                printf("\nCELULA REMOVIDA POR ESTAR VAZIA!\n");
            }
        }
        return (1);
    }
    return (0);
}

void compactarLista(celula **ini, int cont) {
    int i, cont2;
    cont2 = cont;
    celula *aux;
    celula *aux2;
    aux = *ini;
    if (aux == NULL) {
        return;
    }
    while (aux->prox != NULL) {
        while ((cont != 3) && (aux->prox != NULL)) {
            aux2 = aux->prox;
            aux->vetor[cont] = aux2->vetor[0];
            for (i = 0; i < cont; i++) {
                aux->vetor[i] = aux->vetor[i + 1];
            }
            cont2--;
            cont++;
            if (cont2 == 0) {
                aux->prox = aux2->prox;
            }
        }
        aux = aux->prox;
        if (aux == NULL) {
            break;
        }
    }
}

void escreverLista(celula *ini) {
    celula *aux;
    aux = ini;
    int i;
    if (aux == NULL) {
        printf("\nLista Vazia!!");
        return;
    } else {
        while (aux != NULL) {
            printf("( ");
            for (i = 0; i < 3; i++) {
                printf("%d ", aux->vetor[i]);
            }
            printf(")\n");
            aux = aux->prox;
        }
    }
}
