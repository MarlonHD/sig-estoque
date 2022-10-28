#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "validacoes.h"

typedef struct produto Produto;

void moduloProdutos(){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                           = Módulo Produtos =                            ###\n");
    printf("###                                                                          ###\n");
    printf("###               1. Catalogar Produto                                       ###\n");
    printf("###               2. Buscar Produto                                          ###\n");
    printf("###               3. Editar Produto                                          ###\n");
    printf("###               4. Deletar Produto                                         ###\n");
    printf("###               0. Voltar                                                  ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaCatalogarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                          = Catalogar Produto =                           ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaBuscarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                            = Buscar Produto =                            ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaEditarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                            = Editar Produto =                            ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaDeletarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                           = Deletar Produto =                            ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}


/* Funções do módulo produtos */

void cadastrarProduto(void){
    
    Produto* prod;
    prod = (Produto*)malloc(sizeof(Produto));

    do{
        printf("\tDigite o nome do produto: \n\t");
        fgets(prod->nomeProduto, 50, stdin);
    }while(!isNomeValid(prod->nomeProduto));
    // validação do cnpj após finalizar
    printf("\tDigite o CNPJ do fornecedor (apenas números): \n\t");
    fgets(prod->cnpjFornecedor, 20, stdin);

    do{
        printf("\tDigite a categoria do produto: \n\t");
        fgets(prod->categoria, 30, stdin);
    }while(!isNomeValid(prod->categoria));

    do{
        printf("\tDigite o código de barras do produto: \n\t");
        fgets(prod->codProduto, 20, stdin);
    }while(!validBarCode(prod->codProduto));

    exibirProduto(prod);
    free(prod);
}

void preencheProduto(Produto *prod){
    printf("\tDigite o nome do produto: \n\t");
    fgets(prod->nomeProduto, 50, stdin);
    printf("\tDigite o CNPJ do fornecedor (apenas números): \n\t");
    fgets(prod->cnpjFornecedor, 20, stdin);
    printf("\tDigite a categoria do produto: \n\t");
    fgets(prod->categoria, 30, stdin);
    printf("\tDigite o código de barras do produto: \n\t");
    fgets(prod->codProduto, 20, stdin);
}

void exibirProduto(Produto *produto){
    printf("\t################################");
    printf("\t%s", produto->codProduto);
    printf("\t%s", produto->nomeProduto);
    printf("\t%s", produto->categoria);
    printf("\t%s", produto->cnpjFornecedor);
}

void editarProduto(void){
       
    int codProduto;
    printf("\tCódigo do Produto:\n\t");
    scanf("%d", &codProduto);
    getchar();

}

void procurarProduto(void){
    
    char nomeProduto[30];
    printf("\tNome do Produto: \n\t");
    scanf("%s", nomeProduto);
    getchar();
}

void deletarProduto(void) {

    int codProduto;
    printf("\tCódigo do Produto: \n\t");
    scanf("%d", &codProduto);
    getchar();
}