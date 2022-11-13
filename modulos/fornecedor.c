#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fornecedor.h"
#include "validacoes.h"

typedef struct fornecedor Fornecedor;

void moduloFornecedor(void) {
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                          = Módulo Fornecedor =                           ###\n");
    printf("###                                                                          ###\n");
    printf("###               1. Cadastrar Fornecedor                                    ###\n");
    printf("###               2. Procurar Fornecedor                                     ###\n");
    printf("###               3. Editar Fornecedor                                       ###\n");
    printf("###               4. Deletar Fornecedor                                      ###\n");
    printf("###               0. Voltar                                                  ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaCadastrarFornecedor(void){   
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                       = Cadastrar Fornecedor =                           ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaProcurarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                          = Buscar Fornecedor =                           ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaEditarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                         = Editar Fornecedor =                            ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

void telaDeletarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                          = Deletar Fornecedor =                          ###\n");
    printf("###                                                                          ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
}

//funções módulo fornecedor
void cadastrarFornecedor(void){ 

    Fornecedor* fulano;
    fulano = preencheFornecedor();
    gravaFornecedor(fulano);
    exibeFornecedor(fulano);
    getchar();
    free(fulano);
}   

Fornecedor* preencheFornecedor(void){
    Fornecedor* fulano;
    fulano = (Fornecedor*) malloc(sizeof(Fornecedor));
    
    do{
        printf("\tInsira o nome do Fornecedor: \n\t");
        fgets(fulano->nome, 30, stdin);
    }while(!isNomeValid(fulano->nome));
    do{
        printf("\tE-mail: \n\t");
        fgets(fulano->email, 50, stdin);
    }while(!isEmailValid(fulano->email));
    printf("\tInsira o CNPJ do Fornecedor: \n\t");
    fgets(fulano->cnpj, 20, stdin);
    printf("\tInsira o número de telefone: \n\t");
    fgets(fulano->telefone, 20, stdin);
    fulano->status = 'c';

    return fulano;
}

void gravaFornecedor(Fornecedor *fornecedor){
    FILE* fp;
    fp = fopen("./arquivos/fornecedores.dat", "ab");

    if(fp == NULL){
        printf("Erro ao criar o arquivo!");
        exit(1);
    }
    fwrite(fornecedor, sizeof(Fornecedor), 1, fp);
    fclose(fp);
}

void exibeFornecedor(Fornecedor *fornecedor){
    printf("\t#########################\n");
    printf("\t%s", fornecedor->cnpj);
    printf("\t%s", fornecedor->nome);
    printf("\t%s", fornecedor->email);
    printf("\t%s", fornecedor->telefone);
}


void buscarFornecedorNome(char *nome){
    FILE* fp;
    Fornecedor* fulano;
    int cont = 0;

    fulano = (Fornecedor*)malloc(sizeof(Fornecedor));

    fp = fopen("./arquivos/fornecedores.dat","rb");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while(fread(fulano, sizeof(Fornecedor), 1, fp)){
        if((strncmp(fulano->nome, nome, strlen(nome)-1) == 0) && (fulano->status == 'c')){
            cont++;
            exibeFornecedor(fulano);
        }
    }
    if(cont == 0){
        printf("\n\tNenhum fornecedor encontrado com esse nome!\n\t");
    }
    fclose(fp);
    free(fulano);
}

int isFornecedorCad(char *cnpj){
    FILE* fp;
    Fornecedor* fulano;
    int finded = 0;

    fulano = (Fornecedor*)malloc(sizeof(Fornecedor));

    limpaTexto(cnpj);
    fp = fopen("./arquivos/produtos.dat","rb");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while((!finded) && fread(fulano, sizeof(Fornecedor), 1, fp)){
        if((strcmp(fulano->cnpj, cnpj) == 0) && (fulano->status == 'c')){
            finded = 1;
        }
    }
    fclose(fp);
    free(fulano);

    return finded;
}

void atualizaFornecedor(char *cnpj){
    FILE* fp;
    Fornecedor* fulano;
    Fornecedor* fornNovo;
    int finded = 0;
    char opcao;

    fulano = (Fornecedor*)malloc(sizeof(Fornecedor));
    fornNovo = (Fornecedor*)malloc(sizeof(Fornecedor));

    limpaTexto(cnpj);
    fp = fopen("./arquivos/fornecedores.dat","r+b");
    if(fp == NULL){
        printf("404! \nErro na abertura do arquivo!");
        exit(1);
    }
    while((!finded) && fread(fulano, sizeof(Fornecedor), 1, fp)){
        if((strcmp(fulano->cnpj, cnpj) == 0) && (fulano->status == 'c')){
            finded = 1;
        }
    }
    if(!finded){
        printf("\n\tNenhum fornecedor encontrado com esse cnpj!\n");
    }else{
        exibeFornecedor(fulano);
        printf("\n\n");
        printf("\t0.....Cancelar edição\n\t");
        scanf("%c", &opcao);
        if(opcao != '0'){    
            fornNovo = preencheFornecedor();
            fseek(fp, (-1)*sizeof(Fornecedor), SEEK_CUR);
            fwrite(fornNovo, sizeof(Fornecedor), 1, fp);
            printf("\n\tFornecedor alterado com sucesso!\n\t");
        }
    }
    
    fclose(fp);
    free(fulano);
    free(fornNovo);
}

void excluirFornecedor(char *cnpj){
    FILE* fp;
    Fornecedor* fulano;
    int finded = 0;
    char opcao;

    fulano = (Fornecedor*)malloc(sizeof(Fornecedor));

    limpaTexto(cnpj);
    fp = fopen("./arquivos/fornecedores.dat","r+b");
    if(fp == NULL){
        printf("\n\t404! \n\tErro na abertura do arquivo!");
        exit(1);
    }
    while((!finded) && fread(fulano, sizeof(Fornecedor), 1, fp)){
        if((strcmp(fulano-> cnpj, cnpj) == 0) && (fulano->status == 'c')){
            finded = 1;
        }
    }
    if(!finded){
        printf("\n\tNenhum fornecedor encontrado com esse cnpj!\n");
    }else{
        exibeFornecedor(fulano);
        printf("\n\n");
        printf("\t0.....Cancelar\n\t");
        scanf("%c", &opcao);
        if(opcao != '0'){
            fulano->status = '0';
            fseek(fp, (-1)*sizeof(Fornecedor), SEEK_CUR);
            fwrite(fulano, sizeof(Fornecedor), 1, fp);
            printf("\n\tFornecedor excluído!\n\t");
        }
    }
    
    fclose(fp);
    free(fulano);
}


void editarFornecedor(void){
    
    char cnpj[20];
    
    printf("\tCNPJ do fornecedor:\n\t");
    fgets(cnpj, 20, stdin);
    
    atualizaFornecedor(cnpj);
    getchar();
}

void procurarFornecedor(void){
    
    char nomeFornecedor[50];
    
    printf("\tNome do fornecedor: \n\t");
    fgets(nomeFornecedor, 50, stdin);
    
    buscarFornecedorNome(nomeFornecedor);
    getchar();
}

void deletarFornecedor(void) {

    char cnpj[20];

    printf("\tInforme o CNPJ do fornecedor: \n\t");
    fgets(cnpj, 20, stdin);

    excluirFornecedor(cnpj);
    getchar();
}
