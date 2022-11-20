#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"

void telaPrincipal(void) {
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
    char opcao[255];
    printf("\tDigite sua opção: ");
    fgets(opcao, 255, stdin);
    for(int i = 0; opcao[i]!='\0'; i++){
        if(isDigit(opcao[i])){
            return opcao[i];
        }
    }
    return 'm';
}