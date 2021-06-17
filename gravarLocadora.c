/*
 * Função responsável por gravar dados da locadora
 */

#include "libLocadoras.h"
void gravarLocadora(char arqFisicoLocadoras[], Locadora locadora){
   FILE *arq = fopen(arqFisicoLocadoras, "ab");
   
   if(arq == NULL){
      printf("\nErro ao abrir arquivo de Locadoras\n");
      return;
   }

   /*
    * Grava os dados no final do arquivo fisico  
   */

   if (fwrite(&locadora, sizeof(Locadora), 1, arq) == 1){ // gravando os dados recebidos da locadora
      printf("\nDados gravados com sucesso!\n");
   } else printf("\nErro ao gravar dados\n");
   
   fclose(arq);
}