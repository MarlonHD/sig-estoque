#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    
    prod = preencheProduto();
    gravaProduto(prod);
    exibeProduto(prod);
    getchar();
    free(prod);
}

Produto* preencheProduto(void){
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));

    do{
        printf("\tDigite o nome do produto: \n\t");
        fgets(prod->nomeProduto, 50, stdin);
    }while(!isNomeValid(prod->nomeProduto));
    // validação do cnpj após finalizar
    printf("\tDigite o CNPJ do fornecedor (apenas números): \n\t");
    fgets(prod->cnpjFornecedor, 20, stdin);
    limpaTexto(prod->cnpjFornecedor);

    do{
        printf("\tDigite a categoria do produto: \n\t");
        fgets(prod->categoria, 30, stdin);
    }while(!isNomeValid(prod->categoria));

    do{
        printf("\tDigite o código de barras do produto: \n\t");
        fgets(prod->codProduto, 20, stdin);
    }while(!validBarCode(prod->codProduto));

    return prod;
}

void gravaProduto(Produto *prod){
    FILE* fp;
    fp = fopen("./arquivos/produtos.dat","ab");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    fwrite(prod, sizeof(Produto), 1, fp);
    fclose(fp);
}

void exibeProduto(Produto *produto){
    printf("\t################################\n");
    printf("\t%s", produto->codProduto);
    printf("\t%s", produto->nomeProduto);
    printf("\t%s", produto->cnpjFornecedor);
    printf("\t%s", produto->categoria);
}

void buscarProdutoNome(char *nome){
    FILE* fp;
    Produto* prod;
    int cont = 0;

    prod = (Produto*)malloc(sizeof(Produto));

    fp = fopen("./arquivos/produtos.dat","rb");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while(fread(prod, sizeof(Produto), 1, fp)){
        if(strncmp(prod->nomeProduto, nome, strlen(nome)-1) == 0){
            cont++;
            exibeProduto(prod);
        }
    }
    if(cont == 0){
        printf("\n\tNenhum produto encontrado com esse nome!\n");
    }
    free(prod);
}

void buscarProdutoCod(char *codigo){
    FILE* fp;
    Produto* prod;
    int finded = 0;

    prod = (Produto*)malloc(sizeof(Produto));

    limpaTexto(codigo);
    fp = fopen("./arquivos/produtos.dat","rb");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while((!finded) && fread(prod, sizeof(Produto), 1, fp)){
        if(strcmp(prod->codProduto, codigo) == 0){
            exibeProduto(prod);
            finded = 1;
        }
    }
    if(!finded){
        printf("\n\tNenhum produto encontrado com esse código!\n");
    }
    free(prod);
}

void editarProduto(void){
       
    int codProduto;
    printf("\tCódigo do Produto:\n\t");
    scanf("%d", &codProduto);
    getchar();

}

void procurarProduto(void){
    
    char nomeProduto[50];
    printf("\tNome do Produto: \n\t");
    fgets(nomeProduto, 30, stdin);

    buscarProdutoNome(nomeProduto);
    getchar();
}

void deletarProduto(void) {

    int codProduto;
    printf("\tCódigo do Produto: \n\t");
    scanf("%d", &codProduto);
    getchar();
}