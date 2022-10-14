#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

void moduloRelatorios(void) {
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                         = Lista de Relatórios =                          ###\n");
    printf("###                                                                          ###\n");
    printf("###               1. Estoque completo                                        ###\n");
    printf("###               2. Produtos por Fornecedor                                 ###\n");
    printf("###               3. Produtos por Categoria                                  ###\n");
    printf("###               4. Produtos por ID                                         ###\n");
    printf("###               5. Fornecedor por Categoria                                ###\n");
    printf("###               0. Voltar                                                  ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void relatorioCompleto(void){
    system("clear||cls");
    printf("\n");
    printf("###################################################################################################\n");
    printf("#  COD_PRODUTO  #  NOME_PRODUTO  #  CATEGORIA  # ID_PROD. #  NOME FORNECEDOR  #  CNPJ FORNECEDOR  #\n");
    printf("###################################################################################################\n");
    printf("#               |                |             |          |                   |                   #\n");
    printf("#               |                |             |          |                   |                   #\n");
    printf("#               |                |             |          |                   |                   #\n");
    printf("#               |                |             |          |                   |                   #\n");
    printf("###################################################################################################\n");
    printf("\n\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}


