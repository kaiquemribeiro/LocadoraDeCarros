/*
 * Funçao responsavel por listar todos os clientes quando logado como root
 */

#include "libLocadoras.h"
void listarClientes(char arqFisicoClientes[]){
  int achou = 0;
  Cliente cliente;
  FILE *arq = fopen(arqFisicoClientes, "rb");

  if (arq == NULL){
    printf("\nErro ao abrir arquivo de Clientes\n");
    return;
  }

  /*
   * Percorre o arquivo fisico de clientes imprimindo na tela até chegar ao final do arquivo
   */

  while (fread(&cliente, sizeof(Cliente), 1, arq) != 0){
    achou = 1;
    printf("\n****************************************\n");
    printf("\nUsername: %s\n", cliente.login.username);
    printf("\nNome:%s %s\n", cliente.nome, cliente.sobrenome);
    printf("\nData de nascimento: %d/%d/%d\n", cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano);
    printf("\n## Endereco ##\n");
    printf("\nRua: %s, Nº %d | Complemento: %s | Cidade: %s | CEP %d\n", cliente.endereco.rua,
          cliente.endereco.numero, cliente.endereco.complemento, cliente.endereco.cidade, cliente.endereco.cep);
    printf("\n## Contato ##\n");
    printf("\nFone: %s\n", cliente.contato.fone);
    printf("\nEmail: %s\n", cliente.contato.email);
  }

   if(!achou){
    printf("\nNenhum cliente cadastrado!\n");
  } // se não entrar no laço, então não há clientes, então achou continua = 0;
  
  fclose(arq);
}
