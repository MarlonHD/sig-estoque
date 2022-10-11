#include <stdio.h>
#include <stdlib.h>
#include "fornecedor.h"

void moduloFornecedor(void) {
    //char op;
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Módulo Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###            1. Cadastrar Fornecedor                                  ###\n");
    printf("###            2. Procurar Fornecedor                                   ###\n");
    printf("###            3. Editar Fornecedor                                     ###\n");
    printf("###            4. Deletar Fornecedor                                    ###\n");
    printf("###            0. Sair                                                  ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    //printf("###                                                                     ###\n");
    //printf("###            Digite sua opção: ");
    //scanf("%[0-9]", &op);
    //getchar();
    printf("\n");
}

void telaCadastrarFornecedor(void){   
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                    = Cadastrar Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Nome:                                                    ###\n");
    //printf("###            E-mail:                                                  ###\n");
    //printf("###            CNPJ:                                                    ###\n");
    //printf("###            Telefone:                                                ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaProcurarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Buscar Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    //printf("###      Digite o nome do Fornecedor ('0' para listar todos):           ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaEditarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                      = Editar Fornecedor =                          ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Digite o nome do fornecedor:                             ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

void telaDeletarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Deletar Fornecedor =                        ###\n");
    printf("###                                                                     ###\n");
    //printf("###            Digite o nome do fornecedor:                             ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    //printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    //getchar();
}

//funções módulo fornecedor
void cadastrarFornecedor(void){    
    
    char nome[30];
    char email[45];
    char cnpj[20]; //char || int (A definir)
    char numero[13];
    
    printf("\tInsira o nome: \n\t");
    scanf("%s",nome);
    getchar();
    printf("\tE-mail: \n\t");
    scanf("%s", email);
    getchar();
    printf("\tInsira o cnpj: \n\t");
    scanf("%s", cnpj);
    getchar();
    printf("\tInsira o numero: \n\t");
    scanf("%s", numero);
    getchar();

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
