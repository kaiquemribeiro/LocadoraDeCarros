/*
 * Função responsavel por listar locadoras do arquivo texto de locadoras
 */

#include "libLocadoras.h"

int listaLocadorasTexto(){
   Locadora locadora;
    char arqTextoLocadoras[] = "arquivoTextoLocadoras.txt";
    
    FILE *arq = fopen(arqTextoLocadoras, "r");
    if(arq == NULL){
        printf("\nErro ao abrir arquivo texto de locadoras!\n");
        return -1;
    }

    /*
     * Percorre o arquivo .txt lendo as informações das locadoras
     * "%*s" é usado para que o fscanf ignore as strings "Email" e "Fone" 
     */
    while(fscanf(arq, "%s %*s %s %*s %s", locadora.nome, locadora.contato.fone, locadora.contato.email) != EOF){
      printf("\n%s Fone: %s Email: %s\n", locadora.nome, locadora.contato.fone, locadora.contato.email);
    }
    
    fclose(arq);

    return 1;
}
