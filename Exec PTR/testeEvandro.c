#include <stdio.h>

void main(){

  char s[10];

  // Note a atribuicao de valores inteiros
  for (int i=0; i<9; i++){
    s[i] = 65+i;
  }
  s[9]=0;

  printf("t1: %s\n", s);
  // Qual a saida produzida? Como voce explica esta saida? 

  //R: A saída é ABCDEFGHI, pois imprime os caracteres da Tabela Ascii
  // correspondentes aos inteiros atribuídos a s[] 
}