/*
 * Função responsavel por atualizar ou gravar nova avaliação do cliente.
 */

#include "libLocadoras.h"

void atualizaAvaliacaoCliente(char arqFisicoClientes[], char usernameCliente[], char nomeLocadora[], int avaliacao){

  Cliente cliente;
  int achou = 0, i = 0, achou2 = 0, index = 0, flag = 0;

  FILE *arq = fopen(arqFisicoClientes, "r+b"); //abrindo o arquvio
  if (arq == NULL){
    printf("\nErro ao abrir arquivo de Clientes\n");
    return;
  }

 /* 
  * Le o arquivo fisico de clientes, e compara com o username recebido como parametro
  * se for igual, achou = 1 e o loop para.
  */

  while (fread(&cliente, sizeof(Cliente), 1, arq) != 0 && !achou){
    if (strcmp(usernameCliente, cliente.login.username) == 0){
      achou = 1;
    }
  }

  /* 
   * Percorre o vetor de avaliações do cliente em busca da locadora, se achar uma avaliação antiga, sobrescreve
   * senão, vai até o final do vetor e grava uma nova
   */

  if (avaliacao == 2){
    for (i = 0; i < cliente.numeroAvaliacoes; i++){
      if (strcmp(cliente.vetAvaliacoes[i].nomeLocadora, nomeLocadora) == 0){
        achou2 = 1;
        index = i;
      }
    }

    if (achou2){ 
      cliente.vetAvaliacoes[index].avaliacaoLocadora.ruim = 1;
      cliente.vetAvaliacoes[index].avaliacaoLocadora.bom = 0;
      cliente.vetAvaliacoes[index].avaliacaoLocadora.excelente = 0;
    }
    else{
      flag = 1;
      strcpy(cliente.vetAvaliacoes[cliente.numeroAvaliacoes].nomeLocadora, nomeLocadora);
      cliente.vetAvaliacoes[cliente.numeroAvaliacoes].avaliacaoLocadora.ruim = 1;
      cliente.vetAvaliacoes[cliente.numeroAvaliacoes].avaliacaoLocadora.bom = 0;
      cliente.vetAvaliacoes[cliente.numeroAvaliacoes].avaliacaoLocadora.excelente = 0;
    }
  }

  if (avaliacao == 3){
    for (i = 0; i < cliente.numeroAvaliacoes; i++){
      if (strcmp(cliente.vetAvaliacoes[i].nomeLocadora, nomeLocadora) == 0){
        achou2 = 1;
        index = i;
      }
    }

    if (achou2){
      cliente.vetAvaliacoes[index].avaliacaoLocadora.ruim = 0;
      cliente.vetAvaliacoes[index].avaliacaoLocadora.bom = 1;
      cliente.vetAvaliacoes[index].avaliacaoLocadora.excelente = 0;
    }
    else{
      flag = 1; // flag para saber se o cliente ja avaliou ou nao a locadora e alterar o numeroAvaliacoes
      strcpy(cliente.vetAvaliacoes[cliente.numeroAvaliacoes].nomeLocadora, nomeLocadora);
      cliente.vetAvaliacoes[cliente.numeroAvaliacoes].avaliacaoLocadora.ruim = 0;
      cliente.vetAvaliacoes[cliente.numeroAvaliacoes].avaliacaoLocadora.bom = 1;
      cliente.vetAvaliacoes[cliente.numeroAvaliacoes].avaliacaoLocadora.excelente = 0;
    }
  }

  if (avaliacao == 4){
    for (i = 0; i < cliente.numeroAvaliacoes; i++){
      if (strcmp(cliente.vetAvaliacoes[i].nomeLocadora, nomeLocadora) == 0){
        achou2 = 1;
        index = i;
      }
    }

    if (achou2){
      cliente.vetAvaliacoes[index].avaliacaoLocadora.ruim = 0;
      cliente.vetAvaliacoes[index].avaliacaoLocadora.bom = 0;
      cliente.vetAvaliacoes[index].avaliacaoLocadora.excelente = 1;
    }
    else{
      flag = 1;
      strcpy(cliente.vetAvaliacoes[cliente.numeroAvaliacoes].nomeLocadora, nomeLocadora);
      cliente.vetAvaliacoes[cliente.numeroAvaliacoes].avaliacaoLocadora.ruim = 0;
      cliente.vetAvaliacoes[cliente.numeroAvaliacoes].avaliacaoLocadora.bom = 0;
      cliente.vetAvaliacoes[cliente.numeroAvaliacoes].avaliacaoLocadora.excelente = 1;
    }
  }

  /*Se o cliente nunca avaliou a locadora, a flag = 1, então o numero de avaliações é incrementado*/

  if(flag){
    cliente.numeroAvaliacoes++;
  }
  
  
  fseek(arq, -1 * sizeof(Cliente), SEEK_CUR); 
  
  if (fwrite(&cliente, sizeof(Cliente), 1, arq) == 1){ 
    printf("\nAvaliacao gravada com sucesso!\n");
    cliente.numeroAvaliacoes += 1; // adiciona mais uma posicao no controle de avaliacoes do cliente
    fclose(arq);
  }
else{
    printf("\nErro ao gravar avaliacao\n");
    fclose(arq);
  }
}
