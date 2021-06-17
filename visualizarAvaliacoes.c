/*
 * Função responsavel por listar as avaliacoes das locadoras feitas pelo cliente
 */

#include "libLocadoras.h"

void visualizarAvaliacoes(char arqFisicoClientes[], char usernameCliente[]){

  Cliente cliente;
  int achou = 0, i = 0;
  FILE *arq = fopen(arqFisicoClientes, "rb");
  
  if (arq == NULL){
    printf("\nErro ao abrir arquivo de Clientes\n");
    return;
  }
  
  while (fread(&cliente, sizeof(Cliente), 1, arq) != 0 && !achou){
    if (strcmp(cliente.login.username, usernameCliente) == 0){
      achou = 1; //procura e para quando acha o cliente
    }
  }
  
  fseek(arq, -1 * sizeof(Cliente), SEEK_CUR);

  /*Se o o cliente ainda não tiver avaliações, imprime mensagem e retorta*/

  if(!cliente.numeroAvaliacoes){
    printf("\nVoce ainda nao avaliou nenhuma locadora\n");
    return;
  }

  /*Percorre o vetor de avaliações e as imprime*/
  if (achou){
    for (i = 0; i < cliente.numeroAvaliacoes; i++){ // imprime as avaliacoes
      printf("\nLocadora: %s\n", cliente.vetAvaliacoes[i].nomeLocadora);
      if (cliente.vetAvaliacoes[i].avaliacaoLocadora.bom == 1){
        printf("\nAvaliação: Bom\n");
        printf("\n********************\n");
      }
      else if (cliente.vetAvaliacoes[i].avaliacaoLocadora.ruim == 1){
        printf("\nAvaliacao: Ruim\n");
        printf("\n********************\n");
      }
      else if (cliente.vetAvaliacoes[i].avaliacaoLocadora.excelente == 1){
        printf("\nAvaliacao: Execelente\n");
        printf("\n********************\n");
      }
    }
  }
}
