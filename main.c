///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///               Projeto Sistema de Controle de Estoques                   ///
///   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022       ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 8                                 ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "modulos/produto.h"
#include "modulos/estoque.h"
#include "modulos/fornecedor.h"
#include "modulos/relatorios.h"
#include "modulos/validacoes.h"

//Assinatura
void telaPrincipal(void);
void tela_sobre(void);
    


char escolherOpcao(void);


int main(void){
    setlocale(LC_ALL,"Portuguese_Brazil");
    const char SAIR = '0';
    char op;
    char op1 = '0';

    do{
        (op1 == '0') ? telaPrincipal() : 1;
        op = (op1 == '0') ? escolherOpcao() : op;
        switch (op){
            case '1':        
                moduloProdutos();
                op1 = escolherOpcao();
                switch (op1){
                    case '1':
                        telaCatalogarProduto();
                        cadastrarProduto();
                        break;
                    case '2':
                        telaBuscarProduto();
                        procurarProduto();
                        break;
                    case '3':
                        telaEditarProduto();
                        editarProduto();
                        break;
                    case '4':
                        telaDeletarProduto();
                        deletarProduto();
                        break;
                    case '0':
                        break;
                    default:
                        printf("Opção Inválida!!");
                        break;
                }
                break;
            case '2':
                moduloEstoque();
                op1 = escolherOpcao();
                switch (op1){
                    case '1':
                        telaCadastrarEstoque();
                        alterarEstoque('i');
                        break;
                    case '2':
                        telaProcurarEstoque();
                        procurarEstoque();
                        break;
                    case '3':
                        telaRetirarEstoque();
                        alterarEstoque('o');
                        break;
                    case '0':
                        break;
                    default:
                        printf("Opção Inválida!!");
                        break;
                }
                break;
            case '3':
                moduloFornecedor();
                op1 = escolherOpcao();
                switch (op1){
                    case '1':
                        telaCadastrarFornecedor();
                        cadastrarFornecedor();
                        break;
                    case '2':
                        telaProcurarFornecedor();
                        procurarFornecedor();
                        break;
                    case '3':
                        telaEditarFornecedor();
                        editarFornecedor();
                        break;
                    case '4':
                        telaDeletarFornecedor();
                        deletarFornecedor();
                        break;
                    case '0':
                        break;
                    default:
                        printf("Opção Inválida!");
                        break;
                }
                break;
            case '4':
                moduloRelatorios();
                op1 = escolherOpcao();
                switch(op1){
                    case '1':
                        relatorioCompleto();
                        break;
                    case '0':
                        break;
                    default:
                        if(op1 > '1' && op1 < '6'){
                            printf("\n\n\t\t\tEM DESENVOLVIMENTO!\n\n");
                            printf("\t\tPressione <ENTER> para continuar...\n");
                            getchar();
                        }else{
                            printf("Opção inválida!");
                        }
                        break;
                }
                break;
            case '5':
                tela_sobre();
                break;
            case '0':
                break;
            default:
                printf("Opção Inválida!!");
                break;
        }
    }while(op != SAIR);
    return 0;
}

//Funções
void telaPrincipal(void) {
    //char op;
    setlocale(LC_ALL,"Portuguese_Brazil");
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###                = = = Sistema de Controle de Estoques = = =               ###\n");
    printf("###                                                                          ###\n");
    printf("###               1. Módulo Produtos                                         ###\n");
    printf("###               2. Módulo Estoque                                          ###\n");
    printf("###               3. Módulo Fornecedores                                     ###\n");
    printf("###               4. Módulo Relatórios                                       ###\n");
    printf("###               5. Sobre                                                   ###\n");
    printf("###               0. Sair                                                    ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    //printf("###                                                                     ###\n");
    //printf("###            Digite sua opção: ");
    //scanf("%[0-9]", &op);
    //getchar();
    printf("\n");
}

void tela_sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("################################################################################\n");
    printf("###                                                                          ###\n");
    printf("###          = = = = = Sistema de Controle de Estoques = = = = =             ###\n");
    printf("###                                                                          ###\n");
    printf("###   Pojeto de um programa de controle de estoques, desenvolvido em C e     ###\n");
    printf("###   durante a disciplina DCT1106 - Programação, do curso de Bacharelado    ###\n");
    printf("###   em Sistemas de Informação da UFRN. O projeto tem como finalidade a     ###\n");
    printf("###   criação de um programa com as funcionalidades básicas para facilitar   ###\n");
    printf("###   a administração/controle do inventário de uma empresa.                 ###\n");
    printf("###                                                                          ###\n");
    printf("################################################################################\n");
    printf("\n");
    printf("\t\t     #Pressione <ENTER> para seguir... \n");
    getchar();
}


char escolherOpcao(void){
    char opcao;
    printf("\tDigite sua opção: ");
    scanf("%[0-9]",&opcao);
    getchar();
    return opcao;
}