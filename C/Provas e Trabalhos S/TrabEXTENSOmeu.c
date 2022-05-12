#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char escreveCents(int cent);

void main(){
    int num, cent;
    char str[5];
    char *unidades[] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis","dezessete", "dezoito", "dezenove"};
    char *dezenas[] = {"dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    char *centenas[] = {"cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

    while(num != 0 || cent != 0){

        printf("\nInforme o numero, separando com espaco os dois ultimos digitos que devem ser os centavos: "); //ex: xxxx xx
        scanf("%d %d", &num, &cent);
        sprintf(str, "%d", num);   //convertendo variável inteira em string

        //ESCREVENDO OS REAIS
        if(num == 0){
            printf("zero reais ");
        }

        if(num == 1){
            printf("um real ");
        }

        if(num > 1 && num < 20){
            printf("%s reais ", unidades[num-1]);
        }

        if(num > 19 && num < 100){
            if((str[1]-'0') == 0){ //40
                printf("%s reais ", dezenas[(str[0]-'0')-1]);   
            }else
                printf("%s e %s reais ", dezenas[(str[0]-'0')-1], unidades[(str[1]-'0')-1]);
        }

        if(num == 100){
            printf("cem reais ");
        }

        if(num > 100 && num < 1000){
            if((str[2]-'0') == 0 && (str[1]-'0') == 0){  //200
                printf("%s reais ", centenas[(str[0]-'0')-1]);
            }else if((str[2]-'0') == 0){  //220
                printf("%s e %s reais ", centenas[(str[0]-'0')-1], dezenas[(str[1]-'0')-1]);
            }else if((str[1]-'0') == 0){  //202
                printf("%s e %s reais ", centenas[(str[0]-'0')-1], unidades[(str[2]-'0')-1]);
            }else if((str[1]-'0') == 1){  //21x
                printf("%s e %s reais ", centenas[(str[0]-'0')-1], unidades[(str[2]-'0')+9]); 
            }else
                printf("%s e %s e %s reais ", centenas[(str[0]-'0')-1], dezenas[(str[1]-'0')-1], unidades[(str[2]-'0')-1]);      
        }  

        if(num > 999 && num < 10000){
            if((str[1]-'0') == 0 && (str[2]-'0') == 0 && (str[3]-'0') == 0){  //2000
                printf("%s mil reais ", unidades[(str[0]-'0')-1]);
            }else if((str[1]-'0') == 0 && (str[2]-'0') == 0){   //2002
                printf("%s mil e %s reais ", unidades[(str[0]-'0')-1], unidades[(str[3]-'0')-1]);
            }else if((str[1]-'0') == 0 && (str[3]-'0') == 0){   //2020
                printf("%s mil e %s reais ", unidades[(str[0]-'0')-1], dezenas[(str[2]-'0')-1]);
            }else if((str[2]-'0') == 0 && (str[3]-'0') == 0 && (str[1]-'0') != 1){   //2200
                printf("%s mil e %s reais ", unidades[(str[0]-'0')-1], centenas[(str[1]-'0')-1]);
            }else if((str[2]-'0') == 0 && (str[3]-'0') == 0 && (str[1]-'0') == 1){ //2100
                printf("%s mil e cem reais ", unidades[(str[0]-'0')-1]);
            }else if((str[2]-'0') == 1 && (str[1]-'0') == 0 && (str[3]-'0') != 0){  //201x
                printf("%s mil e %s reais ", unidades[(str[0]-'0')-1], unidades[(str[3]-'0')+9]);
            }else if((str[1]-'0') == 0 && (str[2]-'0') != 1){ //2022
                printf("%s mil e %s e %s reais ", unidades[(str[0]-'0')-1], dezenas[(str[2]-'0')-1], unidades[(str[3]-'0')-1]);
            }else if((str[2]-'0') == 1){ //221x
                printf("%s mil %s e %s reais ", unidades[(str[0]-'0')-1], centenas[(str[1]-'0')-1], unidades[(str[3]-'0')+9]);
            }else if((str[2]-'0') == 0){ //2202
                printf("%s mil %s e %s reais ", unidades[(str[0]-'0')-1], centenas[(str[1]-'0')-1], unidades[(str[3]-'0')-1]);
            }else if((str[3]-'0') == 0){ //2220
                printf("%s mil %s e %s reais ", unidades[(str[0]-'0')-1], centenas[(str[1]-'0')-1], dezenas[(str[2]-'0')-1]);
            }else
            printf("%s mil %s e %s e %s reais ", unidades[(str[0]-'0')-1], centenas[(str[1]-'0')-1], dezenas[(str[2]-'0')-1], unidades[(str[3]-'0')-1]);
        }  

        if(num == 10000){
            printf("dez mil reais\n");
        }

        if(num > 10000){
            printf("hmmmm...Ainda nao sei escrever esse numero\n");
        }

        //ESCREVENDO OS CENTAVOS
        escreveCents(cent);
    }
}

char escreveCents(int cent){
    char *unidades[] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis","dezessete", "dezoito", "dezenove"};
    char *dezenas[] = {"dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    char str2[2];
    sprintf(str2, "%d", cent);   //convertendo variável inteira em string

        if(cent == 0){
            printf(" \n");
        }

        if(cent == 1){
            printf("e um centavo\n");
        }

        if(cent > 1 && cent < 20){
            printf("e %s centavos\n", unidades[cent-1]);
        }

        if(cent > 19 && cent < 100){
            if((str2[1]-'0') == 0){
                printf("e %s centavos\n", dezenas[(str2[0]-'0')-1]);
            }else
                printf("e %s e %s centavos \n", dezenas[(str2[0]-'0')-1], unidades[(str2[1]-'0')-1]);
        }
}
/* EXPLICAÇÃO DA ESTRUTURA '(str[0]-'0')'
Como eu converto meu número para uma string, ou seja, um vetor de caracteres
eu não posso usar mais seu conteúdo como índice para o vetor de string pois o
índice so funciona quando é uma varíavel interira. Então ao fazer -'0' eu estou 
convertendo o que era um número em varíavel char para um número int.
Ex: num = 321
    str = '321'
    str[0] = '3', str[1] = '2', str[0] = '1'
    nesse caso acima, os valores são caracteres
    str[0]-'0' = '3'-'0' ==> 3
    agora eu tenho 3 int e não mais char como antes    
*/