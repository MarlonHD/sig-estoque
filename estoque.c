///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///               Projeto Sistema de Controle de Estoques                   ///
///   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022       ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 3                                 ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Assinatura
void telaPrincipal(void);
void tela_sobre(void);
void moduloEstoque(void);
void moduloProdutos(void);
void telaCatalogarProduto(void);
void telaBuscarProduto(void);
void telaEditarProduto(void);
void telaDeletarProduto(void);
int escolherOpcao(void);


int main(void){
    setlocale(LC_ALL,"Portuguese_Brazil");
    const int SAIR = 0;
    int op, op1;

    do{
        telaPrincipal();
        op = escolherOpcao();
        switch (op){
            case 1:        
                moduloProdutos();
                op1 = escolherOpcao();
                switch (op1){
                    case 1:
                        telaCatalogarProduto();
                        break;
                    case 2:
                        telaBuscarProduto();
                        break;
                    case 3:
                        telaEditarProduto();
                        break;
                    case 4:
                        telaDeletarProduto();
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opção Inválida!!");
                        break;
                }
                break;
            case 2:
                moduloEstoque();
                break;
            case 5:
                tela_sobre();
                break;
            case 0:
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
    char op;
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
    printf("###                                                                     ###\n");
    printf("###            Digite sua opção: ");
    scanf("%[0-9]", &op);
    getchar();
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
    char op;
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
    printf("###            1. Catalogar Produto                                     ###\n");
    printf("###            2. Buscar Produto                                        ###\n");
    printf("###            3. Editar Produto                                        ###\n");
    printf("###            4. Deletar Produto                                       ###\n");
    printf("###            0. Sair                                                  ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###            Digite sua opção: ");
    scanf("%[0-9]", &op);
    getchar();
    printf("\n");
}

void moduloEstoque(void) {
    char op;
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
    printf("###                                                                     ###\n");
    printf("###            Digite sua opção: ");
    scanf("%[0-9]", &op);
    getchar();
    printf("\n");
}

void telaCatalogarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Catalogar Produto =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###            Nome do Item:                                            ###\n");
    printf("###            Categoria:                                               ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaBuscarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                         = Buscar Produto =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do item ('0' para listar todos):           ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaEditarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                         = Editar Produto =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do item:                                   ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaDeletarProduto(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Deletar Produto =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do item:                                   ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}


int escolherOpcao(void){
    int opcao;
    printf("Digite sua opção: ");
    scanf("%d",&opcao);
    getchar();
    return opcao;
}