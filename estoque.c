///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///               Projeto Sistema de Controle de Estoques                   ///
///   Developed by Cleomar Junior and Marlon Silva -- since Aug, 2022       ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 4                                 ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Assinatura
void telaPrincipal(void);
void tela_sobre(void);
void moduloEstoque(void);
void moduloProdutos(void);
void moduloFornecedor(void);
void telaCatalogarProduto(void);
void telaBuscarProduto(void);
void telaEditarProduto(void);
void telaDeletarProduto(void);
void telaCadastrarEstoque(void);
void telaProcurarEstoque(void);
void telaEditarEstoque(void);
void telaDeletarEstoque(void);
void telaCadastrarFornecedor(void);
void telaProcurarFornecedor(void);
void telaEditarFornecedor(void);
void telaDeletarFornecedor(void);
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
                op1 = escolherOpcao();
                switch (op1){
                    case 1:
                        telaCadastrarEstoque();
                        break;
                    case 2:
                        telaProcurarEstoque();
                        break;
                    case 3:
                        telaEditarEstoque();
                        break;
                    case 4:
                        telaDeletarEstoque();
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opção Inválida!!");
                        break;
                }
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

void moduloFornecedor(void) {
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
    printf("###                       = Módulo Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###            1. Cadastrar Fornecedor                                  ###\n");
    printf("###            2. Procurar Fornecedor                                   ###\n");
    printf("###            3. Editar Fornecedor                                     ###\n");
    printf("###            4. Deletar Fornecedor                                    ###\n");
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

void telaCadastrarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Cadastrar Estoque =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###            Nome do Item:                                            ###\n");
    printf("###            Quantidade:                                              ###\n");
    printf("###            Fornecedor:                                              ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaProcurarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Procurar Estoque =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do item ('0' para listar todos):           ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaEditarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                         = Editar Estoque =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do item do estoque:                        ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaDeletarEstoque(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                        = Deletar Estoque =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do item:                                   ###\n");
    printf("###                                                                     ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaCadastrarFornecedor(void){   
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                    = Cadastrar Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###            Nome:                                                    ###\n");
    printf("###            E-mail:                                                  ###\n");
    printf("###            CNPJ:                                                    ###\n");
    printf("###            Telefone:                                                ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaProcurarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Buscar Fornecedor =                         ###\n");
    printf("###                                                                     ###\n");
    printf("###      Digite o nome do Fornecedor ('0' para listar todos):           ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaEditarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                      = Editar Fornecedor =                          ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do fornecedor:                             ###\n");
    printf("###                                                                     ###\n");
    printf("###########################################################################\n");
    printf("\n");
    printf("\t\t\t#Pressione <ENTER> para seguir...\n");
    getchar();
}

void telaDeletarFornecedor(void){
    system("clear||cls");
    printf("\n");
    printf("###########################################################################\n");
    printf("###                                                                     ###\n");
    printf("###             = = = Sistema de Controle de Estoques = = =             ###\n");
    printf("###                       = Deletar Fornecedor =                        ###\n");
    printf("###                                                                     ###\n");
    printf("###            Digite o nome do fornecedor:                             ###\n");
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