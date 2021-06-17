/*
 * Função responsavel por exibir os dados do cliente logado
 */

#include "libLocadoras.h"
void visualizaDadosCliente(char arqFisicoClientes[], LogInfo userLog){

  Cliente cliente;
  int achou = 0;

  FILE *arq = fopen(arqFisicoClientes, "rb");
  if (arq == NULL){
    printf("\nErro ao abrir arquivo de Clientes\n");
    return;
  }
  
  while (fread(&cliente, sizeof(Cliente), 1, arq) != 0 && !achou){
    if (strcmp(cliente.login.username, userLog.username) == 0){
      achou = 1; //procura e para quando acha o cliente
      if(achou){
        printf("\nUsername: %s\n", cliente.login.username);
        printf("\nNome:%s %s\n", cliente.nome, cliente.sobrenome);
        printf("\nData de nascimento: %d/%d/%d\n", cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano);
        printf("\n== Endereco ==\n");
        printf("\nRua: %s, Nº %d | Complemento: %s | Cidade: %s | CEP %d\n", cliente.endereco.rua,
              cliente.endereco.numero, cliente.endereco.complemento, cliente.endereco.cidade, cliente.endereco.cep);
        printf("\n== Contato ==\n");
        printf("\nFone: %s\n", cliente.contato.fone);
        printf("\nEmail: %s\n", cliente.contato.email);
      }
    }
  }

}

