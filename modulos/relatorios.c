#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"
#include "estoque.h"
#include "produto.h"
#include "fornecedor.h"

void moduloRelatorios(void) {
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                         = Lista de Relatórios =                          ###\n");
    printf("###                                                                          ###\n");
    printf("###               1. Estoque Completo                                        ###\n");
    printf("###               2. Produtos Catalogados                                    ###\n");
    printf("###               3. Fornecedores Cadastrados                                ###\n");
    printf("###               4. Histórico de Registros                                  ###\n");
    printf("###               5. Produtos por Fornecedor                                 ###\n");
    printf("###               6. Produtos por Categoria                                  ###\n");
    printf("###               0. Voltar                                                  ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void estoqueCompleto(void){
    system("clear||cls");
    printf("\n");
    listarEstoque();
}

void listarEstoque(void){
    FILE* fp;
    Estoque* est;
    est = (Estoque*)malloc(sizeof(Estoque));

    fp = fopen("./arquivos/estoque.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/estoque.dat", "rb");
    while(fread(est, sizeof(Estoque), 1, fp)==1){
        exibeEstoque(est);
    }
    getchar();
    fclose(fp);
}

void histRegistros(void){
    system("clear||cls");
    printf("\n\t");

    FILE* fp;
    Registro* reg;
    reg = (Registro*)malloc(sizeof(Registro));

    fp = fopen("./arquivos/registros.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/registros.dat", "rb");
    if(fp == NULL){
        printf("\n\tFalha na abertura do arquivo!");
        getchar();
        exit(1);
    }
    while(fread(reg, sizeof(Registro), 1, fp)==1){
        exibeRegistro(reg);
    }
    getchar();
    fclose(fp);
}