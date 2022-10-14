#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

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
    
    char nomeProduto[30];
    int cnpjFornecedor;
    char categoria[100];  //Criação das variáveis 

    printf ("\tDigite o nome do produto: \n\t");
    scanf("%s",nomeProduto);
    getchar();
    printf("\tDigite o CNPJ do fornecedor (apenas números): \n\t");
    scanf("%d", &cnpjFornecedor);
    getchar();
    printf("\tDigite a categoria do produto: \n\t");
    scanf("%s",categoria);
    getchar();
}

void editarProduto(void){
       
    int idProduto;
    printf("\tID do Produto:\n\t");
    scanf("%d", &idProduto);
    getchar();

}

void procurarProduto(void){
    
    char nomeProduto[30];
    printf("\tNome do Produto: \n\t");
    scanf("%s", nomeProduto);
    getchar();
}

void deletarProduto(void) {

    int idProduto;
    printf("\tID do Produto: \n\t");
    scanf("%d", &idProduto);
    getchar();
}