#include <stdio.h>
#include <string.h>

int main(){
    char senha[15];
    char senha2[15];

    printf("Escreva sua senha: ");
    scanf("%s", senha);
    printf("Digite a mesma senha: ");
    scanf("%s", senha2);

    if(strcmp(senha, senha2) == 0){
        printf("Sao iguais, siga para o proximo passo");

    }else{
        printf("Sao diferentes, tente novamente");
    }

    return 0;
}