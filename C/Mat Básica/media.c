#include <stdio.h>
 int main(){
     float nota1, nota2, nota3, nota4, resultado;
     char nome[20];

    printf("Informe seu nome: ");
    scanf("%[^\n]", nome);

    printf("Declare sua nota 1: ");
    scanf("%f", &nota1);

    printf("Declare sua nota 2: ");
    scanf("%f", &nota2);

    printf("Declare sua nota 3: ");
    scanf("%f", &nota3);

    printf("Declare sua nota 4: ");
    scanf("%f", &nota4);

    resultado = (nota1 + nota2 + nota3 + nota4) / 4;

    printf("\nYour name is %s and your average grade is %.1f\n", &nome, resultado);

     return 0;
 }