#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "validacoes.h"
#include "fornecedor.h"

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
    
    prod = preencheProduto('c');
    if(prod!=NULL){
        gravaProduto(prod);
        exibeProduto(prod);
        getchar();
    }
    free(prod);
}

Produto* preencheProduto(char opcao){
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));
    char cancel = '1';

    do{
        printf("\tDigite o nome do produto: \n\t");
        fgets(prod->nomeProduto, 50, stdin);
    }while(!isNomeValid(prod->nomeProduto));
    
    do{
        printf("\tDigite o CNPJ do fornecedor (apenas números): \n\t");
        fgets(prod->cnpjFornecedor, 20, stdin);
        limpaTexto(prod->cnpjFornecedor);
        if(!isFornecedorCad(prod->cnpjFornecedor)){
            printf("\n\tCNPJ não cadastrado no sistema!\n");
            printf("\tDeseja cancelar a ação? (Digite: 0)\n\t");
            scanf("%c", &cancel);
        }
    }while((!isFornecedorCad(prod->cnpjFornecedor)) && (cancel!='0'));
    
    if(cancel != '0'){
        do{
            printf("\tDigite a categoria do produto: \n\t");
            fgets(prod->categoria, 30, stdin);
        }while(!isNomeValid(prod->categoria));

        if(opcao == 'c'){
            do{
                printf("\tDigite o código de barras do produto: \n\t");
                fgets(prod->codProduto, 20, stdin);
                if(isProdutoCad(prod->codProduto)){
                    printf("\n\tJá existe um produto cadastrado com esse código!!\n");
                    printf("\tDeseja cancelar o cadastro? (Digite: 0)\n\t");
                    scanf("%c", &cancel);
                }
            }while((!validBarCode(prod->codProduto) || isProdutoCad(prod->codProduto)) && (cancel!='0'));
        }
    }else{
        return NULL;
    }
    
    prod->sit = '1';
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
    printf("################################################################################\n###\n");
    printf("###\tCódigo do Produto:......%s", produto->codProduto);
    printf("###\tNome do Produto:........%s", produto->nomeProduto);
    printf("###\tCNPJ do Fornecedor:.....%s", produto->cnpjFornecedor);
    printf("###\tCategoria:..............%s", produto->categoria);
    printf("###\n");
    printf("################################################################################");
}

void buscarProdutoNome(char *nome){
    FILE* fp;
    Produto* prod;
    int cont = 0;

    prod = (Produto*)malloc(sizeof(Produto));
    // corretor de bug    
    fp = fopen("./arquivos/produtos.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/produtos.dat","rb");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while(fread(prod, sizeof(Produto), 1, fp)){
        if((strncmp(prod->nomeProduto, nome, strlen(nome)-1) == 0) && (prod->sit == '1')){
            cont++;
            exibeProduto(prod);
        }
    }
    if(cont == 0){
        printf("\n\tNenhum produto encontrado com esse nome!\n\t");
    }
    fclose(fp);
    free(prod);
}

int isProdutoCad(char *codigo){
    FILE* fp;
    Produto* prod;
    int finded = 0;
    // corretor de bug    
    fp = fopen("./arquivos/produtos.dat", "ab");
    fclose(fp);

    prod = (Produto*)malloc(sizeof(Produto));

    limpaTexto(codigo);
    fp = fopen("./arquivos/produtos.dat","rb");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while((!finded) && fread(prod, sizeof(Produto), 1, fp)){
        if((strcmp(prod->codProduto, codigo) == 0) && (prod->sit == '1')){
            finded = 1;
        }
    }
    fclose(fp);
    free(prod);

    return finded;
}

void atualizaProduto(char *codigo){
    FILE* fp;
    Produto* prod;
    Produto* prodNovo;
    int finded = 0;
    char opcao = '1';

    // corretor de bug    
    fp = fopen("./arquivos/produtos.dat", "ab");
    fclose(fp);

    prod = (Produto*)malloc(sizeof(Produto));
    prodNovo = (Produto*)malloc(sizeof(Produto));

    limpaTexto(codigo);
    fp = fopen("./arquivos/produtos.dat","r+b");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while((!finded) && fread(prod, sizeof(Produto), 1, fp)){
        if((strcmp(prod->codProduto, codigo) == 0) && (prod->sit == '1')){
            finded = 1;
        }
    }
    if(!finded){
        printf("\n\tNenhum produto encontrado com esse código!\n");
    }else{
        exibeProduto(prod);
        printf("\n\n");
        printf("\t0.....Cancelar edição\n\t");
        scanf("%c", &opcao);
        if(opcao != '0'){    
            prodNovo = preencheProduto('e');
            strcpy(prodNovo->codProduto, prod->codProduto);
            fseek(fp, (-1)*sizeof(Produto), SEEK_CUR);
            fwrite(prodNovo, sizeof(Produto), 1, fp);
            printf("\n\tProduto alterado com sucesso!\n\t");
        }
    }
    
    fclose(fp);
    free(prod);
    free(prodNovo);
}

void excluirProduto(char *codigo){
    FILE* fp;
    Produto* prod;
    int finded = 0;
    char opcao = '1';

    // corretor de bug    
    fp = fopen("./arquivos/produtos.dat", "ab");
    fclose(fp);

    prod = (Produto*)malloc(sizeof(Produto));

    limpaTexto(codigo);
    fp = fopen("./arquivos/produtos.dat","r+b");
    if(fp == NULL){
        printf("\n\t404! \n\tErro na abertura do arquivo!");
        exit(1);
    }
    while((!finded) && fread(prod, sizeof(Produto), 1, fp)){
        if((strcmp(prod->codProduto, codigo) == 0) && (prod->sit == '1')){
            finded = 1;
        }
    }
    if(!finded){
        printf("\n\tNenhum produto encontrado com esse código!\n");
    }else{
        exibeProduto(prod);
        printf("\n\n");
        printf("\t0.....Cancelar\n\t");
        scanf("%c", &opcao);
        if(opcao != '0'){
            prod->sit = '0';
            fseek(fp, (-1)*sizeof(Produto), SEEK_CUR);
            fwrite(prod, sizeof(Produto), 1, fp);
            printf("\n\tProduto excluido com sucesso!\n\t");
        }
    }
    
    fclose(fp);
    free(prod);
}

void editarProduto(void){
       
    char codigo[20];
    printf("\tCódigo do Produto:\n\t");
    fgets(codigo, 20, stdin);
    atualizaProduto(codigo);
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

    char codigo[20];
    printf("\tCódigo do Produto: \n\t");
    fgets(codigo, 20, stdin);
    excluirProduto(codigo);
    getchar();
}