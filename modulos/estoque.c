#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

typedef struct estoque Estoque;

void moduloEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                           = Módulo Estoque =                             ###\n");
    printf("###                                                                          ###\n");
    printf("###               1. Cadastrar Estoque                                       ###\n");
    printf("###               2. Procurar Estoque                                        ###\n");
    printf("###               3. Editar Estoque                                          ###\n");
    printf("###               4. Deletar Estoque                                         ###\n");
    printf("###               0. Voltar                                                  ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaCadastrarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                          = Adicionar Estoque =                           ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaProcurarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                            = Buscar Estoque =                            ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaEditarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                            = Editar Estoque =                            ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaDeletarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                           = Retirar Estoque =                            ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void cadastrarEstoque(void){    //Função cadastrar estoque
    
    Estoque *est;

    est = preencheEstoque();
    gravaEstoque(est);
    exibeEstoque(est);
    getchar();

    free(est);
 
}

Estoque* preencheEstoque(void){
    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));

    //validação com o codigo do produto
    printf("\tInforme o codigo do produto: \n\t");
    fgets(est->codProduto, 20, stdin);
    
    printf("\tInforme a quantidade de produtos: \n\t");
    scanf("%d", &est->quantidade);
    getchar();

    return est;
}

void gravaEstoque(Estoque *est){
    FILE* fp;
    fp = fopen("./arquivos/estoque.dat", "ab");

    if(fp == NULL){
        printf("Erro ao criar o arquivo!");
        exit(1);
    }
    fwrite(est, sizeof(Estoque), 1, fp);
    fclose(fp);
}

void exibeEstoque(Estoque *est){
    printf("\t########################\n");
    printf("\tcodigo: %s", est->codProduto);
    printf("\tquantidade: %d \n", est->quantidade);
}

void editarEstoque(void){
       
    int codProduto;
    int idProduto;
    printf("\tCódigo do Produto:\n\t ");  //provisório
    scanf("%d", &codProduto);
    getchar();
    printf("\tInforme o novo ID do Produto:\n\t");
    scanf("%d", &idProduto);
    getchar();

}

void procurarEstoque(void){
    
    int idProduto;
    printf("\tInforme o ID do Produto: \n\t");
    scanf("%d", &idProduto);
    getchar();
}

void deletarEstoque(void) {

    int codProduto;
    printf("\tCódigo do produto a ser deletado: \n\t");
    scanf("%d", &codProduto);
    getchar();
}
