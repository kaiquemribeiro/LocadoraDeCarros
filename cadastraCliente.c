/*
 * Função responsável por coletar os dados do cliente
 */

#include "libLocadoras.h"

int cadastraCliente(char arqFisicoClientes[], char arqFisicoLogin[], char username[]){
    Cliente cliente;
    LogInfo login;
    int i;

    FILE *arq = fopen(arqFisicoLogin, "rb");
    if (arq == NULL){
        printf("\nErro ao abrir arquivo de Clientes\n");
        return -1;
    }

    /*
     * Percorre o arquivo fisico de login para saber se o username já existe;
     * Caso exista, retorna -1
    */
    while (fread(&login, sizeof(LogInfo), 1, arq) != 0){ 
        if (strcmp(username, login.username) == 0){
            return -1;
        }
    }

    // coletando dados
    strcpy(cliente.login.username, username);
    strcpy(login.username, username);

    printf("\nSenha: \n");
    scanf("\n%[^\n]s", login.passwd);
    printf("\nNome: \n");
    scanf("\n%[^\n]s", cliente.nome);
    printf("\nSobrenome: \n");
    scanf("\n%[^\n]s", cliente.sobrenome);

    printf("\nDia de nascimento \n");
    scanf("\n%d", &cliente.dataNascimento.dia);
    printf("\nMes: \n");
    scanf("\n%d", &cliente.dataNascimento.mes);
    printf("\nAno: \n");
    scanf("\n%d", &cliente.dataNascimento.ano);

    printf("\n== Endereco ==\n");
    printf("\nRua: \n");
    scanf("\n%[^\n]s", cliente.endereco.rua);
    printf("\nNumero: \n");
    scanf("\n%d", &cliente.endereco.numero);
    printf("\nComplemento: \n");
    scanf("\n%[^\n]s", cliente.endereco.complemento);
    printf("\nCidade: \n");
    scanf("\n%[^\n]s", cliente.endereco.cidade);
    printf("\nCEP: \n");
    scanf("\n%d", &cliente.endereco.cep);

    printf("\n== Contatos ==\n");
    printf("\nFone: \n");
    scanf("\n%[^\n]s", cliente.contato.fone);
    printf("\nEmail: \n");
    scanf("\n%[^\n]s", cliente.contato.email);

    cliente.numeroAvaliacoes = 0; // inicializando a variavel de controle das avaliacoes do cliente

    fclose(arq);

    printf("\nGravando cliente...\n");

    gravarCliente(arqFisicoClientes, cliente);  // gravando cliente passando o arquivo e os dados
    gravarNewLogingInfo(arqFisicoLogin, login); // gravando o login passando o arquivo e os dados

    return 0;
}