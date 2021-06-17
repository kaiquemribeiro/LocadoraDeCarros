/*
 * Função responsável por gravar os dados dos clientes no arquivo físico
 */

#include "libLocadoras.h"

void gravarCliente(char arqFisicoClientes[], Cliente c){
   FILE *arq = fopen(arqFisicoClientes, "ab");
   if (arq == NULL){
      printf("\nErro ao abrir arquivo de Clientes\n");
      return;
   }

   /*
    * Escreve os dados no final do arquivo fisico
   */
   
   if(fwrite(&c, sizeof(Cliente), 1, arq) == 1){
      printf("\nDados Gravados com sucesso!\n");
   }else printf("\nErro ao gravar dados!\n");
   
   fclose(arq);
}
