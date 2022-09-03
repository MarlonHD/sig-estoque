///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///               Projeto Sistema de Controle de Estoques                   ///
///   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022       ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 2                                 ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <locale.h>

//Assinatura
void telaPrincipal(void);
void tela_sobre(void);
void moduloEstoque(void);
void moduloProdutos(void);


int main(void){
    setlocale(LC_ALL,"Portuguese_Brazil");

    telaPrincipal();
    return 0;
}

//Funções
void telaPrincipal(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte             ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                 ###\n");
    printf("###               Departamento de Computação e Tecnologia               ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                  ###\n");
    printf("###               Projeto Sistema de Controle de Estoques               ###\n");
    printf("###   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022   ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                                                                     ###\n");
    printf("###            1. Módulo Produtos                                       ###\n");
    printf("###            2. Módulo Estoque                                        ###\n");
    printf("###            3. Módulo Fornecedores                                   ###\n");
    printf("###            4. Módulo Relatórios                                     ###\n");
    printf("###            5. Sobre                                                 ###\n");
    printf("###            0. Sair                                                  ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
}

void tela_sobre(void) {
    printf("\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte                 ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                     ###\n");
    printf("###               Departamento de Computação e Tecnologia                   ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                      ###\n");
    printf("###               Projeto Sistema de Controle de Estoques                   ###\n");
    printf("###      Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022    ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###         = = = = = Sistema de Controle de Estoques = = = = =             ###\n");
    printf("###                                                                         ###\n");
    printf("###  Pojeto de um programa de controle de estoques, desenvolvido em C e     ###\n");
    printf("###  durante a disciplina DCT1106 - Programação, do curso de Bacharelado    ###\n");
    printf("###  em Sistemas de Informação da UFRN. O projeto tem como finalidade a     ###\n");
    printf("###  criação de um programa com as funcionalidades básicas para facilitar a ###\n");
    printf("###  administração/controle do inventário de uma empresa.                   ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
}

void moduloProdutos(void) {
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte             ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                 ###\n");
    printf("###               Departamento de Computação e Tecnologia               ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                  ###\n");
    printf("###               Projeto Sistema de Controle de Estoques               ###\n");
    printf("###   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022   ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Módulo Produtos =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            1. Cadastrar Produto                                     ###\n");
    printf("###            2. Procurar Produto                                      ###\n");
    printf("###            3. Editar Produto                                        ###\n");
    printf("###            4. Deletar Produto                                       ###\n");
    printf("###            0. Sair                                                  ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
}

void moduloEstoque(void) {
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte             ###\n");
    printf("###                 Centro de Ensino Superior do Seridó                 ###\n");
    printf("###               Departamento de Computação e Tecnologia               ###\n");
    printf("###                  Disciplina DCT1106 -- Programação                  ###\n");
    printf("###               Projeto Sistema de Controle de Estoques               ###\n");
    printf("###   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022   ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Módulo Estoque =                           ###\n");
    printf("###                                                                     ###\n");
    printf("###            1. Cadastrar Estoque                                     ###\n");
    printf("###            2. Procurar Estoque                                      ###\n");
    printf("###            3. Editar Estoque                                        ###\n");
    printf("###            4. Deletar Estoque                                       ###\n");
    printf("###            0. Sair                                                  ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
}