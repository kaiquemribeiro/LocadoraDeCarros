/*
 * Responsavel pela alteração de dados das locadoras
 */

#include "libLocadoras.h"
void alterarLocadora(char arqFisicoLocadoras[]){
   
   Locadora locadora;
   int achou = 0;
   char nomeLocadora[40];

   printf("\nDigite o nome da locadora\n");
   scanf("\n%[^\n]s", nomeLocadora);
   
   FILE *arq = fopen(arqFisicoLocadoras, "r+b");
   
   if (arq == NULL){
       printf("\nErro ao abrir arquivo de locadoras.\n"); 
       return;
   }

   /*Procura pela locadora no arquivo fisico, se achar, a variavel achou = 1 e o loop para;
    *Se não achar, fecha o arquivo e retorna -1;
    *Se achar, coleta os novos dados, em seguida reposiciona o cursor no começo da struct e
    *sobrescreve os dados.
    */

   while (fread(&locadora, sizeof(Locadora), 1, arq) != 0 && !achou){ 
      if (strcmp(nomeLocadora, locadora.nome) == 0){
      achou = 1;
         if(achou){                 
            printf("\nRua: \n");
            scanf("\n%[^\n]s", locadora.endereco.rua);
            printf("\nNumero: \n");
            scanf("%d", &locadora.endereco.numero);
            printf("\nCEP: \n");
            scanf("%d", &locadora.endereco.cep);
            printf("\nCidade\n");
            scanf("\n%[^\n]s", locadora.endereco.cidade);
            printf("\nComplemento\n");
            scanf("\n%[^\n]s", locadora.endereco.complemento);
                  
            printf("\n\nTelefone: ");
            scanf("\n%[^\n]s", locadora.contato.fone);
            printf("\nEmail: \n");
            scanf("\n%[^\n]s", locadora.contato.email);
                  
            printf("\nCategoria (Digite 1 para disponivel e 0 para indisponivel): \n");
            locadora.tipoDeCarro.pequeno = setaCategoria("Pequeno");
            locadora.tipoDeCarro.medio = setaCategoria("Medio");
            locadora.tipoDeCarro.grande = setaCategoria("Grande");
            locadora.tipoDeCarro.premium = setaCategoria("Premium");
            locadora.tipoDeCarro.SUV = setaCategoria("SUV");
            locadora.tipoDeCarro.conversivel = setaCategoria("Conversivel");
            locadora.tipoDeCarro.minivan = setaCategoria("Minivan");
                  
            
            fseek(arq, -1 * sizeof(Locadora), SEEK_CUR); 
            if (fwrite(&locadora, sizeof(Locadora), 1, arq) == 1){ 
               printf("\nDados atualizados com sucesso!\n");
            } else printf("\nErro ao atualizar os dados.\n");
         }
      }
   }
  
   if(!achou){
      printf("\nLocadora nao encontrada!\n");
      fclose(arq);
      return;
   }
   
   fclose(arq);
}
