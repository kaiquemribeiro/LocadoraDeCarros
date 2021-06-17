// Menu chamando as funções de acordo com o que é digitado no menu pelo root

//libLocadoras.h é inclusa para que a função logAsRoot tenha acesso às definições de registros, funções e constantes
#include "libLocadoras.h"
void logAsRoot(char arqFisicoClientes[], char arqFisicoLogin[], char arqFisicoLocadoras[]){
    
    printf("\n**** Bem vindo root **** \n");
    int opt, idLocadora;
    char username[MAX_USER];

    menuRoot();
    scanf("%d", &opt);
    while (opt != 13){
        
        switch (opt){
        case 1:
            printf("\nInsira o username\n");
            scanf("\n%[^\n]s", username);
            if (cadastraCliente(arqFisicoClientes, arqFisicoLogin, username) == -1){
                printf("\nUsername Ja cadastrado!\n");
            }
            break;
        case 2:
            cadastraLocadora(arqFisicoLocadoras);
            break;
        case 3:
            printf("\nInsira o username\n");
            scanf("\n%[^\n]s", username);
            if (alterarCliente(arqFisicoClientes, username) == -1){
                printf("\nCliente nao cadastrado! \n");
            }
            break;
        case 4:
            alterarLocadora(arqFisicoLocadoras);
            break;
        case 5:
            printf("\nInsira um username\n");
            scanf("\n%[^\n]s", username);
            if (removerCliente(arqFisicoClientes, arqFisicoLogin, username) == -1){
                printf("\nCliente nao cadastrado! \n");
            } else printf("\nCliente removido com sucesso!\n");
            break;
        case 6:
            printf("\nDigite o ID da locadora: \n");
            scanf("%d", &idLocadora);
            removerLocadora(arqFisicoLocadoras, idLocadora);
            break;
        case 7:
            listarClientes(arqFisicoClientes);
            break;
        case 8:
            listarLocadoras(arqFisicoLocadoras);
            break;
        case 9:
            geraArquivoTextoClientes(arqFisicoClientes);
            break;
        case 10:
            geraArquivoTextoLocadoras(arqFisicoLocadoras);
            break;
        case 11:
            if(listaClientesTexto() == -1){
                printf("\nErro ao abrir arquivo texto de clientes\n");
            }
            break;
        case 12:
            listaLocadorasTexto();
            break;
        default:
            printf("\nOpcao Invalida\n");
            break;
        }

        menuRoot();
        scanf("%d", &opt);
    }
}
