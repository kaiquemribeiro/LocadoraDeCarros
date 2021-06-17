/*
 * Função responsável por gravar as informação de login do novo cliente (newUserLoginInfo) no arquivo arqFisicoLogin.
 */

#include "libLocadoras.h"
void gravarNewLogingInfo(char arqFisicoLogin[], LogInfo newUserLoginInfo){
    
    FILE *pArqLogin = fopen(arqFisicoLogin, "ab");
    if (pArqLogin == NULL){
        printf("\nErro ao abrir arquivo de login em gravar NewLoginINfo.\n");
        return;
    }
    
    if(fwrite(&newUserLoginInfo, sizeof(LogInfo), 1, pArqLogin) == 1){
        printf("\nLogin gravado com sucesso!\n");
    } else printf("\nErro ao gravar login!\n");
    
    fclose(pArqLogin);
}
