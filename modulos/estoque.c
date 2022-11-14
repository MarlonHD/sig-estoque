#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estoque.h"
#include "produto.h"
#include "validacoes.h"

typedef struct estoque Estoque;

void moduloEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                           = Módulo Estoque =                             ###\n");
    printf("###                                                                          ###\n");
    printf("###               1. Cadastrar no Estoque                                    ###\n");
    printf("###               2. Procurar no Estoque                                     ###\n");
    printf("###               3. Retirar do Estoque                                      ###\n");
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

void telaRetirarEstoque(void){
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

int quantidade(char *codigo){
    FILE* fp;
    Estoque* est;
    est = (Estoque*)malloc(sizeof(Estoque));
     // corretor de bug    
    fp = fopen("./arquivos/estoque.dat", "ab");
    fclose(fp);

    fp = fopen("./arquivos/estoque.dat","rb");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while(fread(est, sizeof(Estoque), 1, fp)){
        if(strcmp(est->codProduto, codigo)){
            return est->quantidade;
        }
    }
    return -1;
}

Registro* preencheRegistro(char tipo){ //tipo == 'i' ? input : output
    Registro* reg;
    time_t tempo;
    time(&tempo);

    reg = (Registro*)malloc(sizeof(Registro));
    reg->tempo = tempo;
    reg->conteudo = preencheEstoque();
    
    if(tipo == 'i'){
        reg->tipo = tipo;
    }

    return reg;
}

Estoque* preencheEstoque(void){
    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));

    char cancel = '1';
    char quant[10];

    do{
        printf("\tInforme o codigo do produto: \n\t");
        fgets(est->codProduto, 20, stdin);
        if(!isProdutoCad(est->codProduto)){
            printf("\n\tProduto não cadastrado no sistema!\n");
            printf("\tDeseja cancelar a ação? (Digite: 0)\n\t");
            scanf("%c", &cancel);
        }
    }while((!isProdutoCad(est->codProduto)) && (cancel!='0'));
    
    if(cancel == '0'){
        return NULL;
    }
    do{
        printf("\tInforme a quantidade de produtos(apenas números): \n\t");
        fgets(quant, 10, stdin);
    }while(!isNumValid(quant));

    est->quantidade = atoi(quant);
    
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

void cadastrarEstoque(void){    //Função cadastrar estoque
    
    Estoque *est;

    est = preencheEstoque();
    gravaEstoque(est);
    exibeEstoque(est);
    getchar();

    free(est);
 
}
void procurarEstoque(void){
    
    int idProduto;
    printf("\tInforme o ID do Produto: \n\t");
    scanf("%d", &idProduto);
    getchar();
}

void retirarEstoque(void) {

    int codProduto;
    printf("\tCódigo do produto a ser deletado: \n\t");
    scanf("%d", &codProduto);
    getchar();
}
