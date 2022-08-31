///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///               Projeto Sistema de Controle de Estoques                   ///
///   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022       ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 1                                 ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <locale.h>

//Assinatura
void telaPrincipal(void);


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