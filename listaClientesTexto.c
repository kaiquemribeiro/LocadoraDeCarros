/*
 * Função responsável por listar clientes presentes no arquivo texto de clientes
 */

#include "libLocadoras.h"

int listaClientesTexto(){
    Cliente cliente;

    char arqTextoClientes[] = "arquivoTextoClientes.txt";
    
    FILE *arq = fopen(arqTextoClientes, "r");

    /*
     * Percorre o arquivo fisico gravando lendo os dados contidos nele
     * "%*s" é usado para que o fscanf ignore as string "Email" e "Fone" 
     */

    if(arq == NULL){
        return -1;
    }
    
    while(fscanf(arq, "%s %s %*s %s %*s %s", 
        cliente.nome, cliente.sobrenome, cliente.contato.fone, cliente.contato.email) != EOF){
        printf("\n%s %s Fone: %s Email: %s\n", cliente.nome, cliente.sobrenome, cliente.contato.fone, cliente.contato.email);
    }

    fclose(arq);

    return 1;
}
