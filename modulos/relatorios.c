#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "estoque.h"
#include "produto.h"
#include "fornecedor.h"
#include "validacoes.h"

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
    printf("###               7. Fornecedores em ordem alfabética                        ###\n");
    printf("###               8. Produtos em ordem alfabética                            ###\n");
    printf("###               0. Voltar                                                  ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void estoqueCompleto(void){
    system("clear||cls");
    printf("\n");

    FILE* fp;
    Estoque* est;
    est = (Estoque*)malloc(sizeof(Estoque));
    int cont = 0;

    fp = fopen("./arquivos/estoque.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/estoque.dat", "rb");
    while(fread(est, sizeof(Estoque), 1, fp)==1){
        exibeEstoque(est);
        cont++;
    }
    if(!cont){
        printf("\n\tNão há elementos a serem exibidos!");
        printf("\n\tPressione qualquer tecla para continuar...");
    }
    getchar();
    fclose(fp);
    free(est);
}

void histRegistros(void){
    system("clear||cls");
    printf("\n");

    FILE* fp;
    Registro* reg;
    reg = (Registro*)malloc(sizeof(Registro));
    int cont = 0;

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
        cont++;
    }
    if(!cont){
        printf("\n\tNão há elementos a serem exibidos!");
        printf("\n\tPressione qualquer tecla para continuar...");
    }
    getchar();
    fclose(fp);
    free(reg);
}

void produtosCat(void){
    system("clear||cls");
    printf("\n");

    FILE* fp;
    Produto* prod;
    prod = (Produto*)malloc(sizeof(Produto));
    int cont = 0;

    fp = fopen("./arquivos/produtos.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/produtos.dat", "rb");
    if(fp == NULL){
        printf("\n\tFalha na abertura do arquivo!");
        getchar();
        exit(1);
    }
    while(fread(prod, sizeof(Produto), 1, fp)==1){
        exibeProduto(prod);
        cont++;
    }
    if(!cont){
        printf("\n\tNão há elementos a serem exibidos!");
        printf("\n\tPressione qualquer tecla para continuar...");
    }
    getchar();
    fclose(fp);
    free(prod);
}

void fornecedoresCad(void){
    system("clear||cls");
    printf("\n");

    FILE* fp;
    Fornecedor* forn;
    forn = (Fornecedor*)malloc(sizeof(Fornecedor));
    int cont = 0;

    fp = fopen("./arquivos/fornecedores.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/fornecedores.dat", "rb");
    if(fp == NULL){
        printf("\n\tFalha na abertura do arquivo!");
        getchar();
        exit(1);
    }
    while(fread(forn, sizeof(Fornecedor), 1, fp)==1){
        exibeFornecedor(forn);
        cont++;
    }
    if(!cont){
        printf("\n\tNão há elementos a serem exibidos!");
        printf("\n\tPressione qualquer tecla para continuar...");
    }
    getchar();
    fclose(fp);
    free(forn);
}

char* getFiltro(int op){
    char* filtro;
    filtro = (char*)malloc(sizeof(char)*30);
    if(op == 1){
        do{
        printf("\tDigite o CNPJ do fornecedor (apenas números): \n\t");
        fgets(filtro, 30, stdin);
        limpaTexto(filtro);
    }while(!isFornecedorCad(filtro));
    }else if(op == 2){
        do{
            printf("\tDigite a categoria do produto: \n\t");
            fgets(filtro, 30, stdin);
        }while(!isNomeValid(filtro));
    }else{
        return NULL;
    }
    return filtro;
}

void prod_filtro(int op){
    FILE* fp;
    Produto* prod;
    prod = (Produto*)malloc(sizeof(Produto));

    fp = fopen("./arquivos/produtos.dat", "ab");
    fclose(fp);
    fp = fopen("./arquivos/produtos.dat", "rb");
    if(fp == NULL){
        printf("\n\tFalha na abertura do arquivo!");
        getchar();
        exit(1);
    }

    char* filtro = getFiltro(op);
    if(op == 1){
        while((fread(prod, sizeof(Produto), 1, fp)==1)){
            if(strcmp(prod->cnpjFornecedor,filtro)==0){
                exibeProduto(prod);
                if(isOnEstoque(prod->codProduto)){
                    printf("\tQuantidade: %d\n", quantidade(prod->codProduto));
                }else{
                    printf("\tQuantidade: 0\n");
                }
                
            }
        }
    }else if(op == 2){
        while (fread(prod, sizeof(Produto),1, fp)==1){
            if(strcmp(prod->categoria, filtro)==0){
                exibeProduto(prod);
                if(isOnEstoque(prod->codProduto)){
                    printf("\tQuantidade: %d\n", quantidade(prod->codProduto));
                }else{
                    printf("\tQuantidade: 0\n");
                }
            }
        }
    }

    getchar();
    fclose(fp);
    free(filtro);
}

void forneAlfab(void){
    int cont = 0;
  Fornecedor* forn;
  FILE* fp;
  forn = (Fornecedor*) malloc(sizeof(Fornecedor));
  for(int i = 0; i <= 25; i++){
    fp = fopen("./arquivos/fornecedores.dat", "r+b");
    while((fread(forn, sizeof(Fornecedor), 1, fp))){
      if(forn->nome[0] == 65+i || forn->nome[0] == 97+i){
        cont++;
        printf("\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
        "///  FORNECEDOR %6i                                                       ///\n", cont);
        exibeFornecedor(forn);
        printf("\n");
      }
    }
    fclose(fp);
    }
    if(cont == 0){
    printf("\n"
      "////////////////////////////////////////////////////////////////////////////////\n"
      "///                                                                          ///\n"
      "///                       Nenhum Fornecedor Cadastrado                       ///\n"
      "///                                                                          ///\n"
      "////////////////////////////////////////////////////////////////////////////////\n");
  }
    
  free(forn);
  getchar();
  system("clear || cls");
}

void prodAlfab(void){
    int cont = 0;
  Produto* prod;
  FILE* fp;
  prod = (Produto*) malloc(sizeof(Produto));
  for(int i = 0; i <= 25; i++){
    fp = fopen("./arquivos/produtos.dat", "r+b");
    while((fread(prod, sizeof(Produto), 1, fp))){
      if(prod->nomeProduto[0] == 65+i || prod->nomeProduto[0] == 97+i){
        cont++;
        printf("\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
        "///  PRODUTO %6i                                                          ///\n", cont);
        exibeProduto(prod);
        printf("\n");
      }
    }
    fclose(fp);
    }
    if(cont == 0){
    printf("\n"
      "////////////////////////////////////////////////////////////////////////////////\n"
      "///                                                                          ///\n"
      "///                        Nenhum Produto Cadastrado                         ///\n"
      "///                                                                          ///\n"
      "////////////////////////////////////////////////////////////////////////////////\n");
  }
  free(prod);
  getchar();
  system("clear || cls");
}
