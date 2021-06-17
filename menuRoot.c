/*
 * Lista as operações que podem ser realizadas pelo usuário root.
*/
#include "libLocadoras.h"

void menuRoot()
{
   printf("\n==== Root =====");
   printf("\n1 - Cadastrar cliente.");
   printf("\n2 - Cadastrar locadora.");
   printf("\n3 - Alterar dados do cliente.");
   printf("\n4 - Alterar dados da locadora.");
   printf("\n5 - Remover cliente.");
   printf("\n6 - Remover locadora.");
   printf("\n7 - Listar todos os clientes.");
   printf("\n8 - Listar todas as locadoras.");
   printf("\n9 - Gera lista de clientes em arquivo texto.");
   printf("\n10 - Gera lista de locadoras em arquivo texto.");
   printf("\n11 - Lê clientes listados no arquivo texto e os imprime da saída.");
   printf("\n12 - Lê locadoras listadas no arquivo texto e as imprime da saída.");
   printf("\n13 - Logout.");
   printf("\n=======================\n");
}
