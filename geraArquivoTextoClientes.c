/*
 * Função responsável por gerar arquivo .txt dos clientes
 */

#include "libLocadoras.h"

void geraArquivoTextoClientes(char arqFisicoClientes[]){
  Cliente cliente;
  char arqTextoClientes[] = "arquivoTextoClientes.txt";
  
  FILE *arq = fopen(arqFisicoClientes, "rb");
  
  if(arq == NULL){
    printf("\nErro ao abrir arquivo fisico clientes!\n");
    return;
  }

  FILE *arq2 = fopen(arqTextoClientes, "w");
  
  if(arq2 == NULL){
    printf("\nErro ao abrir arquivo texto clientes!\n");
    return;
  }

  printf("\nGerando arquivo...\n");
  
  /*
   * Percorre o arquivo fisico de clientes, e imprime no arquivo .txt o nome, sobrenome, 
   * telefone e email
  */
  while(fread(&cliente, sizeof(Cliente), 1, arq) != 0){
    fprintf(arq2, "%s %s Fone: %s Email: %s", cliente.nome, cliente.sobrenome, cliente.contato.fone, cliente.contato.email);
    fprintf(arq2, "\n");
  }
  printf("\nArquivo gerado com sucesso!\n");
  
  fclose(arq);
  fclose(arq2);
}
