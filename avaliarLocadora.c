/*
 * Funcao responsavel por colher a avaliacao do cliente e adicionar ao total da locadora
 */

#include "libLocadoras.h"
int avaliarLocadora(char arqFisicoLocadoras[], char nomeLocadora[]){
    int opt = -1, achou = 0;

    Locadora locadora;

    FILE *arq = fopen(arqFisicoLocadoras, "r+b");
    if (arq == NULL){
        printf("\nErro ao abrir arquivo de Locadoras\n"); 
        return -1;
    }

    /* 
     * Procura a locadora no arquivo fisico, se achar, achou = 1 e o loop para
     * e então atualiza a avaliação da locadora
     */
    
    while (fread(&locadora, sizeof(Locadora), 1, arq) != 0 && !achou){
        if (strcmp(nomeLocadora, locadora.nome) == 0){
            achou = 1;
            printf("\nAvaliacao para a locadora %s : 2 para RUIM, 3 para BOA ou 4 para EXCELENTE: \n", locadora.nome);
            scanf("%d", &opt);
            if (opt == 2){ // adiciona avaliacao ao total
                locadora.avaliacao.ruim += 1;
            }
            else if (opt == 3){
                locadora.avaliacao.bom += 1;
            }
            else if (opt == 4){
                locadora.avaliacao.excelente += 1;
            }

            fseek(arq, -1 * sizeof(Locadora), SEEK_CUR); // reposiciona o cursor
            fwrite(&locadora, sizeof(Locadora), 1, arq); // grava os dados
            fclose(arq);
            return opt; // retorna a nota do cliente
        }
    }

    fclose(arq);

    return opt; // se nao encontrar a locadora, retorna -1
}