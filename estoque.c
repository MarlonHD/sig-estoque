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

//Assinatura
void telaPrincipal(void);


int main(void){
    telaPrincipal();
    return 0;
}

//Funções
void telaPrincipal(void) {
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             Universidade Federal do Rio Grande do Norte             ###\n");
    printf("###                 Centro de Ensino Superior do Serid%c                 ###\n",162);
    printf("###               Departamento de Computa%c%co e Tecnologia               ###\n",135,198);
    printf("###                  Disciplina DCT1106 -- Programa%c%co                  ###\n",135,198);
    printf("###               Projeto Sistema de Controle de Estoques               ###\n");
    printf("###   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022   ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                                                                     ###\n");
    printf("###            1. M%cdulo Produtos                                       ###\n",162);
    printf("###            2. M%cdulo Estoque                                        ###\n",162);
    printf("###            3. M%cdulo Fornecedores                                   ###\n",162);
    printf("###            4. M%cdulo Relat%crios                                     ###\n",162,162);
    printf("###            5. Sobre                                                 ###\n");
    printf("###            0. Sair                                                  ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
}