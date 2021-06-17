/*
 * Função responsável por coletar dados da locadora
 */

#include "libLocadoras.h"

void cadastraLocadora(char arqFisicoLocadoras[]){
    
    int id = 0, achou = 0;
    char nomelocadora[40];
    Locadora locadora;

    printf("\nNome da Locadora\n");
    scanf("\n%[^\n]s", nomelocadora);

    FILE *arq = fopen(arqFisicoLocadoras, "r+b");
    if(arq == NULL){
        printf("\nErro ao abrir arquivo de Locadoras\n");
        return;
    }


                
    /*
     * Procura o nome passado no arquivo fisico para saber se a locadora ja esta cadastrada, 
     * se encontrar, pede que o usuario escreva um novo nome e procura novamente 
     */

    while(fread(&locadora, sizeof(Locadora), 1, arq) != 0){ 
        achou = 1;
        if (strcmp(nomelocadora, locadora.nome) == 0){ 
            printf("\nLocadora ja cadastrada, digite outro nome\n");
            scanf("\n%[^\n]s", nomelocadora); 
            rewind(arq);
        }
    }
    
    /*
     * Verficando se é a primeira locadora a ser cadastrada, se for, recebe ID 1
     * se não for, seta o cursor no final do arquivo
     * sendo assim, pega o id da ultima locadora cadastrada e adiciona 1
     * solução encontrada para que o ID das locadoras nunca se repita
     */

    if(!achou){
        id = 1;
    } else {
        fseek(arq, 0, SEEK_END);
        fseek(arq, -1 * sizeof(Locadora), SEEK_CUR);
        fread(&locadora, sizeof(Locadora), 1, arq);
        id = locadora.id + 1;
    }

    locadora.id = id;
    strcpy(locadora.nome, nomelocadora);
    printf("\n== Endereco ==\n");
    printf("\nRua: \n");
    scanf("\n%[^\n]s", locadora.endereco.rua);
    printf("\nNumero: \n");
    scanf("\n%d", &locadora.endereco.numero);
    printf("\nComplemento: \n");
    scanf("\n%[^\n]s", locadora.endereco.complemento);
    printf("\nCidade: \n");
    scanf("\n%[^\n]s", locadora.endereco.cidade);
    printf("\nCEP: \n");
    scanf("\n%d", &locadora.endereco.cep);

    printf("\n== Contato ==\n");
    printf("\nTelefone: \n");
    scanf("\n%[^\n]s", locadora.contato.fone);
    printf("\nemail: \n");
    scanf("\n%[^\n]s", locadora.contato.email);

    printf("\nCategoria (Digite 1 para disponivel e 0 para indisponivel): \n");
    locadora.tipoDeCarro.pequeno = setaCategoria("Pequeno");
    locadora.tipoDeCarro.medio = setaCategoria("Medio");
    locadora.tipoDeCarro.grande = setaCategoria("Grande");
    locadora.tipoDeCarro.premium = setaCategoria("Premium");
    locadora.tipoDeCarro.SUV = setaCategoria("SUV");
    locadora.tipoDeCarro.conversivel = setaCategoria("Conversivel");
    locadora.tipoDeCarro.minivan = setaCategoria("Minivan");

    locadora.avaliacao.ruim = 0;
    locadora.avaliacao.bom = 0; // inicializando as variaveis de avaliacoes
    locadora.avaliacao.excelente = 0;

    fclose(arq);

    printf("\nGravando locadora...\n");

    gravarLocadora(arqFisicoLocadoras, locadora); //grava locadora passando arquivo e dados
}
