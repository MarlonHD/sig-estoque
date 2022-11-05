#include <stdio.h>
#include <stdlib.h>
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

void editarFornecedor(void){
    
    char cnpj[20];
    char nome[30];
    char email[45];
    char numero[13];
    
    printf("\tCNPJ do fornecedor:\n\t");
    scanf("%s", cnpj);
    getchar();

    //validação
    //se validação = ok
        printf("\tInsira o novo nome: \n\t");
        scanf("%s",nome);
        getchar();
        printf("\tNovo E-mail: \n\t");
        scanf("%s", email);
        getchar();
        printf("\tInsira o novo numero: \n\t");
        scanf("%s", numero);
        getchar();

}

void procurarFornecedor(void){
    
    char nomeFornecedor[30];
    printf("\tNome do fornecedor: \n\t");
    scanf("%s", nomeFornecedor);
    getchar();
}

void deletarFornecedor(void) {

    char cnpj[20];
    printf("\tInforme o CNPJ do fornecedor: \n\t");
    scanf("%s", cnpj);
    getchar();
}
