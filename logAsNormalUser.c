#include "libLocadoras.h"

void logAsNormalUser(char arqFisicoClientes[], char arqFisicoLocadoras[], LogInfo userLog){

   printf("\n**** Bem vindo %s **** \n", userLog.username);
   menuCliente(userLog.username);
   int opt, retorno;
   scanf("%d", &opt);
   while (opt != 7){
      switch (opt){
      case 1:
         visualizaDadosCliente(arqFisicoClientes, userLog);
         break;
      case 2:
        if(alterarCliente(arqFisicoClientes, userLog.username) == -1){
           printf("\n\nCliente Nao cadastrado!");
        }
         break;
      case 3:
         listarLocadoras(arqFisicoLocadoras);
         break;
      case 4:
         printf("\nNome da locadora a avaliar: ");
         char nomeLocadora[40];
         scanf("\n%[^\n]s", nomeLocadora);
         int avaliacao = avaliarLocadora(arqFisicoLocadoras, nomeLocadora);
         if (avaliacao == -1){
            printf("\nLocadora %s não cadastrada\n", nomeLocadora);
         } else if (avaliacao > 1 && avaliacao <= 4){
            atualizaAvaliacaoCliente(arqFisicoClientes, userLog.username, nomeLocadora, avaliacao);
         } else printf("\nNota invalida\n");

         break;
      case 5:
         visualizarAvaliacoes(arqFisicoClientes, userLog.username);
         break;
      case 6:
         if(listaLocadorasTexto() == -1){
            printf("\nErro na abertura do arquivo texto locadoras\n");
         }
         break;
      }
      menuCliente(userLog.username);
      scanf("%d", &opt);
   }
}
