#include <stdio.h>

int main(){
    int q20, q50, saque, x, y, Qnotas, aux;
    x = y = 1;
    q20 = 20;
    q50 = 20;

    while(saque != 0){
     printf("Informe o valor do saque: ");            /* operação de resto --> n % d */
     scanf("%d", &saque);

      if(saque == 0){
        printf("QUANTIDADE DE CEDULAS DE 50 RESTANTES NO CAIXA: %d\n", q50); 
        printf("QUANTIDADE DE CEDULAS DE 20 RESTANTES NO CAIXA: %d\n", q20);
      break;
     }

    if (saque > (50*q50 + 20*q20)){
        printf("Nao ha saldo suficiente para compor o saque\n");        

    }else
         if(saque == 70){
             q50 = q50 - 1;
             q20 = q20 - 1;
             printf("Total de notas no saque: 2\n");
             printf("Total de notas de 50 reais no saque: 1\n");
             printf("Total de notas de 20 reais no saque: 1\n");
         }else    

         if((saque % 70) == 0){
            if(q20 <= 0 || q50 <= 0){ 
                printf("NÃO TEMOS MAIS NOTAS PARA ESSE SAQUE");
                q20 = 0;
                q50 = 0;
            break;
            }else                                     /* numeros divisiveis por 70 (140, 210, 280...) */
           for(x; 50*x+20*y<saque; x++){              /* qntd igual de notas de 20 e 50 na saida */
              y++;
           } 
            Qnotas = x + y;
            q20 = q20 - y;
            q50 = q50 - x;
            printf("Total de notas no saque: %d\n", Qnotas);
            printf("Total de notas de 50 reais no saque: %d\n", x);
            printf("Total de notas de 20 reais no saque: %d\n", y);

         }else
              if(saque % 100 == 90){ 
                 if(q20 <= 0 || q50 <= 0){ 
                   printf("NÃO TEMOS MAIS NOTAS PARA ESSE SAQUE");
                 break;
                 }else                                    /* numeros como 190, 290... */
                 aux = saque - 40;                        /* qntd pre determinada de notas de 20 -> 2 */
                 x = aux / 50;
                 Qnotas = x + 2;
                 q50 = q50 - x;
                 q20 = q20 - 2;
                 printf("Total de notas no saque: %d\n", Qnotas);
                 printf("Total de notas de 50 reais no saque: %d\n", x);
                 printf("Total de notas de 20 reais no saque: 2\n");

              }else
                   if(saque % 100 == 10){  
                     if(q20 <= 0 || q50 <= 0){ 
                        printf("NÃO TEMOS MAIS NOTAS PARA ESSE SAQUE");
                     break;
                     }else                           /* numeros como 110, 310... */
                    aux = saque - 60;                /* qntd pre determinada de notas de 20 -> 3 */ 
                    x = aux / 50; 
                    Qnotas = x + 3;
                    q50 = q50 - x;
                    q20 = q20 - 3;
                    printf("Total de notas no saque: %d\n", Qnotas);
                    printf("Total de notas de 50 reais no saque: %d\n", x);
                    printf("Total de notas de 20 reais no saque: 3\n");

                   }else
                        if(saque % 100 == 30){   
                           if(q20 <= 0 || q50 <= 0){ 
                              printf("NÃO TEMOS MAIS NOTAS PARA ESSE SAQUE");
                           break;
                           }else                                /* numeros como 130, 230, 330... */
                         aux = saque - 80;                      /* qntd pre determinada de notas de 20 -> 4 */ 
                         x = aux / 50;
                         Qnotas = x + 4;
                         q50 = q50 - x;
                         q20 = q20 - 4;
                         printf("Total de notas no saque: %d\n", Qnotas);
                         printf("Total de notas de 50 reais no saque: %d\n", x);
                         printf("Total de notas de 20 reais no saque: 4\n");
  
                        }else
                             if((saque % 100) == 70){
                                if(q20 <= 0 || q50 <= 0){ 
                                   printf("NÃO TEMOS MAIS NOTAS PARA ESSE SAQUE");
                                break;
                               }else                               /* numeros como 170, 270, 370...*/
                              aux = saque - 20;                    /* qntd pre determinada de notas de 20 -> 1 */
                              x = aux / 50;
                              Qnotas = x + 1;
                              q50 = q50 - x;
                              q20 = q20 - 1;
                              printf("Total de notas no saque: %d\n", Qnotas);
                              printf("Total de notas de 50 reais no saque: %d\n", x);
                              printf("Total de notas de 20 reais no saque: 1\n");

                             }else
                                  if((saque % 50) == 0){
                                     if(q50 <= 0){
                                        printf("NAO TEMOS MAIS NOTAS DE 50\n");
                                     break;
                                     }else
                                   Qnotas = saque / 50;
                                   q50 = q50 - Qnotas;
                                   printf("Total de notas de 50 reais no saque: %d\n", Qnotas);

                                  }else 
                                       if((saque % 20) == 0){
                                          if(q20 <= 0){
                                             printf("NAO TEMOS MAIS NOTAS DE 20\n");
                                          break;
                                          }else
                                        Qnotas = saque / 20;
                                        q20 = q20 - Qnotas;
                                        printf("Total de notas de 20 reais no saque: %d\n", Qnotas);

                                       }else{
                                             printf("Nao existem cedulas para o valor solicitado\n");
                                      }                                      
                                                
    printf("QUANTIDADE DE CEDULAS DE 50 RESTANTES NO CAIXA: %d\n", q50); 
    printf("QUANTIDADE DE CEDULAS DE 20 RESTANTES NO CAIXA: %d\n", q20); 

    }

    return 0;
}