/*
 * Função responsavel por gerar o arquivo texto com as locadoras cadastradas
 */

#include "libLocadoras.h"

void geraArquivoTextoLocadoras(char arqFisicoLocadoras[]){

 Locadora locadora;
 char arqTextoLocadoras[] = "arquivoTextoLocadoras.txt";

  FILE *arq = fopen(arqFisicoLocadoras, "rb");
  if(arq == NULL){
    printf("\nErro ao abrir arquivo fisico locadoras\n");
    return;
  }

  FILE *arq2 = fopen(arqTextoLocadoras, "w");
  if(arq2 == NULL){
    printf("\nErro ao criar arquivo texto clientes\n");
    return;
  }

  printf("\nGerando arquivo...\n");

  /*
   * Percorre o arquivo fisico de locadoras e grava no arquivo .txt o nome,
   * o fone e o email
  */

  while(fread(&locadora, sizeof(Locadora), 1, arq) != 0){
    fprintf(arq2, "%s Fone: %s Email: %s\n", locadora.nome, locadora.contato.fone, locadora.contato.email);
  }

  printf("\nArquivo gerado com sucesso!\n");
  
  fclose(arq);
  fclose(arq2);
}