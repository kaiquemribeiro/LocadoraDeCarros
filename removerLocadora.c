/*
 * Função responsavel por remover locadora do cadastro
 */

#include "libLocadoras.h"

void removerLocadora(char arqFisicoLocadoras[], int idLocadora){

    Locadora locadora;
    int achou = 0;

    FILE *arq = fopen(arqFisicoLocadoras, "r+b");
    if (arq == NULL){
        printf("\nErro ao abrir arquivo de locadoras!\n");
    }

    FILE *arqTmp = fopen("temporario.bin", "wb"); // criando um arquivo temporario para os dados a serem atualizados
    if (arqTmp == NULL){
        printf("\nErro ao abrir arquivo temporario de locadoras\n");
    }

    while (fread(&locadora, sizeof(Locadora), 1, arq) != 0){ // procura locadora pelo id
        if (locadora.id == idLocadora){
            achou = 1;
        }
        else{
            fwrite(&locadora, sizeof(Locadora), 1, arqTmp);
        }
    }

    fclose(arq);
    fclose(arqTmp);

    if(!achou){
        remove("temporario.bin");
        printf("\nLocadora não encontrada!\n");
        return;
    }

    if(remove(arqFisicoLocadoras) == 0 && rename("temporario.bin", arqFisicoLocadoras) == 0){
        printf("\nLocadora removida com sucesso!\n");
    } // apaga o arquivo antigo que contem a locadora a ser removida 
      // renomeia o arquivo os dados atualizados para o nome do arquivo de locadoras
}