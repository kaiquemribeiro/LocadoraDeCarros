/*
 * Função responsavel por listar todas as locadoras
 */

#include "libLocadoras.h"
void listarLocadoras(char arqFisicoLocadoras[]){
  Locadora locadora;
  int achou = 0;

  FILE *arq = fopen(arqFisicoLocadoras, "rb");
  
  if (arq == NULL){
    printf("\nErro ao abrir arquivo de Locadoras\n");
    return;
  }

  /*
   * Percorre o arquivo fisico de locadoras até o final listando todas as locadoras  
   */

  while (fread(&locadora, sizeof(Locadora), 1, arq) != 0){
    achou = 1;
    printf("\n****************************************\n");
    printf("\nLocadora: %s | ID: %d\n", locadora.nome, locadora.id);
    printf("\nRua: %s, Nº %d | Complemento: %s | Cidade: %s | CEP: %d \n", locadora.endereco.rua,
           locadora.endereco.numero, locadora.endereco.complemento, locadora.endereco.cidade, locadora.endereco.cep);
    printf("\n== Contato ==\n");
    printf("\nFone: %s\n", locadora.contato.fone);
    printf("\nEmail: %s\n", locadora.contato.email);
    printf("\n## Carros ##\n");

    /*
     * Imprime "disponivel" se o valor for igual a 1 e i"ndisponivel" se não for  
     */

    if (locadora.tipoDeCarro.conversivel == 1){
      printf("\nConversivel: Disponivel\n");
    }
    else printf("\nConversivel: Indisponivel\n");

    if (locadora.tipoDeCarro.grande == 1){
      printf("\nGrande: Disponivel\n");
    }
    else printf("\nGrande: Indisponivel\n");

    if (locadora.tipoDeCarro.medio == 1){
      printf("\nMedio: Disponivel\n");
    }
    else printf("\nMedio: Indisponivel\n");

    if (locadora.tipoDeCarro.pequeno == 1){
      printf("\nPequeno: Disponivel\n");
    }
    else printf("\nPequeno: Indisponivel\n");

    if (locadora.tipoDeCarro.minivan == 1){
      printf("\nMinivan: Disponivel\n");
    }
    else printf("\nMinivan: Indisponivel\n");

    if (locadora.tipoDeCarro.premium == 1){
      printf("\nPremium: Disponivel\n");
    }
    else printf("\nPremium: Indisponivel\n");

    if (locadora.tipoDeCarro.SUV == 1){
      printf("\nSUV: Disponivel\n");
    }
    else printf("\nSUV: Indisponivel\n");

    printf("\n## Avaliacoes ##\n");
    printf("\nRuim (%d / %d)\n", locadora.avaliacao.ruim, locadora.avaliacao.ruim + locadora.avaliacao.bom + locadora.avaliacao.excelente);
    printf("\nBom (%d / %d)\n", locadora.avaliacao.bom, locadora.avaliacao.ruim + locadora.avaliacao.bom + locadora.avaliacao.excelente);
    printf("\nExcelente (%d / %d)\n", locadora.avaliacao.excelente, locadora.avaliacao.ruim + locadora.avaliacao.bom + locadora.avaliacao.excelente);
  } // imprimindo as avaliacoes e o total de avaliacoes ja feitas
  
  if(!achou){
    printf("\nNenhuma locadora cadastrada!\n");
  } // se não entrar no laço, então não há locadora, então achou continua = 0;

  fclose(arq);
}
