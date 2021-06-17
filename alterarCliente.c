/*
 * Função responsavel pelas alterações nos dados do cliente.
 */

#include "libLocadoras.h"
int alterarCliente(char arqFisicoClientes[], char usernameCliente[]){
   
   Cliente cliente;
   int achou = 0;

   FILE *arq = fopen(arqFisicoClientes, "r+b");
   
   if (arq == NULL){
       printf("\nErro ao abrir arquivo de Clientes\n"); 
       return -1;
    }
   
   /*
    * Lê o arquivo, se o username passado como parametro for igual o username, achou recebe 1;
    * Escreve sobrescreve os dados na variavel, em seguida reposiciona o cursor pro começo da 
    * struct e grava os novos dados sobrescrevendo os antigos;
    * Se não achou o cliente, retorna -1
    */

   while (fread(&cliente, sizeof(Cliente), 1, arq) != 0 && !achou){
      if (strcmp(usernameCliente, cliente.login.username) == 0){
         achou = 1;
            if(achou){
               printf("\nRua: \n");
               scanf("\n%[^\n]s", cliente.endereco.rua);
               printf("\nNumero: \n");
               scanf("%d", &cliente.endereco.numero);
               printf("\nCEP: \n");
               scanf("%d", &cliente.endereco.cep);
               printf("\nCidade\n");
               scanf("\n%[^\n]s", cliente.endereco.cidade);
               printf("\nComplemento\n");
               scanf("\n%[^\n]s", cliente.endereco.complemento);
               printf("\n\nTelefone: ");
               scanf("\n%[^\n]s", cliente.contato.fone);
               printf("\nEmail: \n");
               scanf("\n%[^\n]s", cliente.contato.email);

               fseek(arq, -1 * sizeof(Cliente), SEEK_CUR);
                  
                  if (fwrite(&cliente, sizeof(Cliente), 1, arq) == 1){
                     printf("\nDados atualizados com sucesso!\n");
                  } else printf("\nErro ao atualizar os dados.\n");
      }
   } 
}

   fclose(arq);
   
   if(!achou) return -1;

   return 0;
}
